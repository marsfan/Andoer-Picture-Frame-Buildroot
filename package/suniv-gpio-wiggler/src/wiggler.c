#include <stdio.h>
#include <stdint.h>
#include <gpiod.h>
#include <unistd.h>



int main()
{
    int line_number;
    int iteration;
    int value = 0;
    char keep_going = 'n';
    const char *chipname = "gpiochip0";
    struct gpiod_chip *chip;
    struct gpiod_line *line;
    chip = gpiod_chip_open_by_name(chipname);
    
    while (1) {
        printf("Enter the Port D number to wiggle: ");
        scanf("%d", &line_number);
        if (line_number > 21 || line_number < 0) {
            printf("Goodbye.\n");
            gpiod_chip_close(chip);
            return 0;
        }
        printf("Wiggling Port D%d\n", line_number);
        line_number = 3 * 32 + line_number;
        line = gpiod_chip_get_line(chip, line_number);
        gpiod_line_request_output(line, "wiggler", value);
        for (iteration = 0; iteration < 20; iteration++)
        {
            gpiod_line_set_value(line, value);
            value = !value;
            usleep(250000);
        }
        gpiod_line_release(line);
    }


}