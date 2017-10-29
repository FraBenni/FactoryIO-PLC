#include <stdio.h>
#include <stdint.h>

typedef union
{
	uint8_t  iec_uint8;
	uint16_t iec_uint16;
	uint32_t iec_uint32;
	uint64_t iec_uint64;

	int8_t   iec_int8;
	int16_t  iec_int16;
	int32_t  iec_int32;
	int64_t  iec_int64;

	float    iec_single;
	double   iec_double;
} iec_type_t;

extern void hello_world();
extern void config_init();
extern void init_variables();

extern void config_run();
extern iec_type_t read_variable(size_t type, size_t idx);
extern void set_variable(iec_type_t in, size_t type, size_t idx);


int main()
{
	hello_world();

	init_variables();

	iec_type_t t;

	// Cycle 1
    printf("Cycle 1\n");
    config_run();
    t = read_variable(0, 0);
	printf("uint8: %d\n", t.iec_uint8);

    // Cycle 2
    printf("Cycle 2\n");
	t.iec_uint8 = 1;
    set_variable(t, 0, 0);
    config_run();
    t = read_variable(0, 0);
	printf("uint8: %d\n", t.iec_uint8);
    
	// Cycle 3
    printf("Cycle 3\n");
	t.iec_uint8 = 0;
    set_variable(t, 0, 0);
    config_run();
    t = read_variable(0, 0);
	printf("uint8: %d\n", t.iec_uint8);

	return 0;
}