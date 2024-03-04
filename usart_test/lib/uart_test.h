#ifndef USART_TEST_H
#define USART_TEST_H

#include <stdio.h>
#include <string.h>
#include <stm32f4xx.h>


#define UART_HEAD              	0xC0
#define UART_TAIL              	0xFE
#define UART_ACK               	0xCC
#define UART_OK               	0
#define UART_FAIL			   	1
#define UART_RESTART_TIMEOUT    500

typedef enum
{
	STATE_START,
	STATE_WAITING_LEN,
	STATE_RECEIVED_LEN,
	STATE_WAITING_PACKET,
	STATE_RECEIVED_PACKET,
	STATE_RECEIVED,
	STATE_PACKET_FAILED,

	STATE_SEND_LEN,
	STATE_WAITING_OK,
	STATE_SEND_PACKET

}uart_state_e;


typedef union
{
	struct
	{
		uint8_t u8head;
		uint8_t u8data[2];
		uint8_t u8checksum;
		uint8_t u8tail;
	};

	uint8_t _raw[5];
}packet_u;

typedef struct
{
	uart_state_e eState;
	UART_HandleTypeDef *handler;
	uint32_t msTiming;
	uint8_t u8Ack;
	uint8_t u8data[2];

	packet_u uPacketRec;
	uint8_t u8ExpectedLen;

	packet_u uPacketTrs;
	uint8_t u8SendLen;
}uart_control_t;


void uart_start(uart_control_t *control, UART_HandleTypeDef *uart);

void uart_mac_state(uart_control_t *control, uint32_t TimeMs);

void uart_send_packet(uart_control_t *control, uint8_t *data);

void uart_rx_event(uart_control_t *control);

void uart_tx_event(uart_control_t *control);

void uart_received_callback(uart_control_t *control, uint8_t *data, uint8_t len);



#endif
