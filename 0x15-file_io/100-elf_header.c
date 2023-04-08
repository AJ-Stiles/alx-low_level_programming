#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define ERROR_CODE 98

/**
 * print_error - print an error message and exit with an error code
 * @message: error message to be printed
 *
 * Return: void
 */
void print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(ERROR_CODE);
}

/**
 * print_elf_header - print the ELF header
 * @header: pointer to the ELF header structure
 *
 * Return: void
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	/* Print the magic numbers */
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	/* Print the rest of the fields in the header */
	printf("  Class:                             %s\n",
	       header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
	       header->e_ident[EI_DATA] == ELFDATA2MSB ? "big endian" : "little endian");
	printf("  Version:                           %d%s\n",
	       header->e_ident[EI_VERSION],
	       header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
		break;
	}
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header->e_type)
	{
	case ET_NONE:
		printf("NONE (Unknown Type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared Object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %d>\n", header->e_type);
		break;
	}
	printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * main - entry point for the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
