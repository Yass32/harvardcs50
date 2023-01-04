#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2) //Make sure user gives only one command line arguement
    {
      printf("Usage: ./recover IMAGE");
      return 1;
    }

    FILE *file = fopen(argv[1], "r"); //Open file

    if (file == NULL) //Check if file is valid to read
    {
      printf("Error, cannot open file\n");
      return 1;
    }

    unsigned char buffer[512];
    int image_count = 0;
    //Create file pointer for recovered image
    FILE *second_file = NULL;
    char *file_name = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, file)) //Read blocks of 512 bytes
    {
      //Check if bytes indicates that its a jpeg file
      if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
      {
          sprintf(file_name, "%03i.jpg", image_count);
          second_file = fopen(file_name, "w");
          image_count++;
      }
      if (second_file != NULL) //Check if output file is valid to write
      {
          fwrite(buffer, sizeof(char), 512, second_file);
      }
    }
    free(file_name);
    fclose(second_file);
    fclose(file);

    return 0;
}