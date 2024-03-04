#include "uart_test.h"



uint8_t _uart_calc_checksum(packet_u *pck)
{
	uint8_t u8ChkSum, i;

	u8ChkSum = 0;
	for(i=0; i < (sizeof(packet_u)-2); i++)
		u8ChkSum += pck->_raw[i];

	return u8ChkSum;
}




uint8_t _uart_verify_packet(uart_control_t *control)
{
	packet_u *pck;
	uint8_t u8ChkSum;

	pck = &control->uPacketRec;
	if(pck->u8head != UART_HEAD)
	{
		control->eState = STATE_PACKET_FAILED;
		return UART_FAIL;
	}
	else if(pck->u8tail != UART_TAIL)
	{
		control->eState = STATE_PACKET_FAILED;
		return UART_FAIL;
	}
	u8ChkSum = _uart_calc_checksum(pck);
	if(u8ChkSum != pck->u8checksum)
	{
		control->eState = STATE_PACKET_FAILED;
		return UART_FAIL;
	}

	memcpy(control->u8data, pck->u8data, sizeof(pck->u8data));
	control->eState = STATE_RECEIVED;
	return UART_OK;
}





void uart_start(uart_control_t *control, UART_HandleTypeDef *uart)
{
	memset(control, 0, sizeof(uart_control_t));
	control->eState = STATE_START;
	control->handler = uart;
	control->u8Ack = UART_ACK;
}




void uart_mac_state(uart_control_t *control, uint32_t TimeMs)
{
	UART_HandleTypeDef *handle;

	handle = control->handler;
	switch (control->eState) {
		case STATE_START:
			HAL_UART_Receive_DMA(handle, &control->u8ExpectedLen, sizeof(uint8_t));
			control->eState = STATE_WAITING_LEN;
			break;

		case	STATE_WAITING_LEN:

			break;

		case	STATE_RECEIVED_LEN:
			control->u8Ack = UART_ACK;
			HAL_UART_Transmit_DMA(handle, &control->u8Ack, sizeof(uint8_t));
			HAL_UART_Receive_DMA(handle, control->uPacketRec._raw, control->u8ExpectedLen);
			control->eState = STATE_WAITING_PACKET;
			control->msTiming = TimeMs;
			break;

		case	STATE_WAITING_PACKET:
			if((TimeMs - control->msTiming) > UART_RESTART_TIMEOUT)
				control->eState = STATE_START;
			break;

		case	STATE_RECEIVED_PACKET:
			if(_uart_verify_packet(control) == UART_OK)
				uart_received_callback(control, control->u8data, sizeof(control->u8data));
			break;

		case	STATE_RECEIVED:
		case	STATE_PACKET_FAILED:
			control->eState = STATE_START;
			break;

		case	STATE_SEND_LEN:
			HAL_UART_Receive_DMA(handle, &control->u8Ack, sizeof(uint8_t));
			HAL_UART_Transmit_DMA(handle, &control->u8SendLen, sizeof(uint8_t));
			control->eState = STATE_WAITING_OK;
			control->msTiming = TimeMs;
			break;

		case	STATE_WAITING_OK:
			if((TimeMs - control->msTiming) > UART_RESTART_TIMEOUT)
				control->eState = STATE_START;
			break;
		case	STATE_SEND_PACKET:
			HAL_UART_Transmit_DMA(handle, control->uPacketTrs._raw, control->u8SendLen);
			control->eState = STATE_START;
			break;
		default:
			break;
	}
}




void uart_send_packet(uart_control_t *control, uint8_t *data)
{
	packet_u *pck;
	pck = &control->uPacketTrs;
	pck->u8head = UART_HEAD;
	pck->u8tail = UART_TAIL;
	memcpy(pck->u8data, data, sizeof(pck->u8data));
	pck->u8checksum = _uart_calc_checksum(pck);

	control->u8SendLen = sizeof(packet_u);
	control->eState = STATE_SEND_LEN;
}




void uart_rx_event(uart_control_t *control)
{
	switch(control->eState)
	{
	default:
		break;
	}
}




void uart_tx_event(uart_control_t *control)
{
	switch(control->eState)
	{
	case STATE_WAITING_OK:
		if(control->u8Ack == UART_ACK)
			control->eState = STATE_SEND_PACKET;
		else
			control->eState = STATE_START;
		break;

	case STATE_WAITING_LEN:
		control->eState = STATE_RECEIVED_LEN;
		break;

	case STATE_WAITING_PACKET:
		control->eState = STATE_RECEIVED_PACKET;
		break;

	default:
		break;
	}
}




__attribute__((weak)) void uart_received_callback(uart_control_t *control, uint8_t *data, uint8_t len)
{

}
