#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @head: pointer to the head of the linked list
 *
 * Return: number of nodes in the linked list
 */
size_t print_listint(const listint_t *head)
{
    size_t num_nodes = 0;
    char num_buffer[12];  // Buffer to store integer as a string

    while (head != NULL)
    {
        // Convert integer to a string
        int num_digits = snprintf(num_buffer, sizeof(num_buffer), "%d", head->n);

        // Allocate memory for the string on the heap
        char *str = malloc((num_digits + 1) * sizeof(char));
        if (str == NULL)
        {
            exit(EXIT_FAILURE);
        }

        // Copy the string from the buffer to the heap
        for (int i = 0; i <= num_digits; i++)
        {
            *(str + i) = *(num_buffer + i);
        }

        // Print the string
        write(1, str, num_digits);
        write(1, "\n", 1);

        // Free the allocated memory
        free(str);

        num_nodes++;
        head = head->next;
    }

    return num_nodes;
}

