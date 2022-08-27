/*
 * @Description    :
 * @Author         : Aiyangsky
 * @Date           : 2022-08-27 16:02:47
 * @LastEditors    : Aiyangsky
 * @LastEditTime   : 2022-08-27 16:22:00
 * @FilePath       : \Container\example\Container_example.c
 */

#include <stdio.h>
#include <string.h>

#include "Ring_Fifo.h"

unsigned char buffer[1024];
RING_FIFO_CB_T fifo;

typedef struct
{
    int number;
    int data;
} TEST_NODE_T;
TEST_NODE_T node[10];
TEST_NODE_T node_out[10];

int main()
{
    unsigned int i = 0;
    memset(node_out, 0, sizeof(TEST_NODE_T) * 10);
    Ring_Fifo_init(&fifo, sizeof(TEST_NODE_T), buffer, sizeof(buffer));

    for (i = 0; i < 10; i++)
    {
        node[i].data = i;
        node[i].number = i;
    }

    Ring_Fifo_in_cell(&fifo, &node[0]);
    Ring_Fifo_in_cells(&fifo, &node[1], 9);

    Ring_Fifo_out_cells(&fifo, &node_out[0], 9);
    Ring_Fifo_out_cell(&fifo, &node_out[9]);

    for (i = 0; i < 10; i++)
    {
        printf("\nnode%d: num:%d data: %d\n", i, node[i].number, node[i].data);
        printf("node rec%d: num:%d data: %d\n", i, node_out[i].number, node_out[i].data);
    }

    return 0;
}