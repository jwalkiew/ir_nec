#include <avr/io.h>
#include <stdlib.h>

#include "nec.h"
#include "commands.h"

#define LED_RED_PIN PD7
#define LED_RED_SET (PORTD |= (1 << LED_RED_PIN))
#define LED_RED_CLR (PORTD &= ~(1 << LED_RED_PIN))

#define LED_YELLOW_PIN PD6
#define LED_YELLOW_SET (PORTD |= (1 << LED_YELLOW_PIN))
#define LED_YELLOW_CLR (PORTD &= ~(1 << LED_YELLOW_PIN))

#define LED_BLUE_PIN PD5
#define LED_BLUE_SET (PORTD |= (1 << LED_BLUE_PIN))
#define LED_BLUE_CLR (PORTD &= ~(1 << LED_BLUE_PIN))

int main(void) {
	uint32_t current_command = 0;
	uint32_t last_command = 0;

	PORTD = 0xFF;
	DDRD |= (1 << IR_PIN) | (1 << LED_RED_PIN) | (1 << LED_YELLOW_PIN) | (1 << LED_BLUE_PIN);

	ir_init();

	while (1) {
		current_command = get_current_command();

		if (current_command == last_command)
			continue;

		switch (current_command) {
			case COMMAND_CH_MINUS:
				LED_RED_CLR;
				break;

			case COMMAND_CH_PLUS:
				LED_RED_SET;
				break;

			case COMMAND_PREV:
				LED_YELLOW_CLR;
				break;

			case COMMAND_NEXT:
				LED_YELLOW_SET;
				break;

			case COMMAND_VOL_MINUS:
				LED_BLUE_CLR;
				break;

			case COMMAND_VOL_PLUS:
				LED_BLUE_SET;
				break;

			default:
				break;
		}

		last_command = current_command;
	}
}
