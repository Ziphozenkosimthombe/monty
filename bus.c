#include "monty.h"

static bus_t bus = {NULL, NULL, NULL, 0};
/**
 * get_bus - nothing happen
 *
 * Return: &bus
 */
bus_t *get_bus(void)
{
	return (&bus);
}
