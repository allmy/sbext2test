#include <stdio.h>                            
#include <fcntl.h>
#include <stdlib.h>          				/* para O_RDONLY */
#include <time.h>            				/* para time_t, pero sin uso ahora */
#include <sys/stat.h>
#include <linux/fs.h>
#include </usr/include/ext2fs/ext2_fs.h>
#include </usr/include/linux/magic.h> 		/* para reconocer el fs */

/*---------------------------------------------------------------------------*/
/*---------------------- Super block parsing function -----------------------*/
/*---------------------------------------------------------------------------*/

int analize_sb(char volume)
{
	printf("DEBUG %s\n", volume);
	struct ext2_super_block es;
	int f;
	char free[1024];

	f = open(volume, O_RDONLY);
	read(f, free, 1024);
	read(f, &es, sizeof(struct ext2_super_block));

	/* Cabecera */

	printf("%s\t %.20s\t %20.20s\t %20.80s\t\n",
		"Variable",
		"Valor",
		"Valor humanizado",
		"Descripcion");
	printf("-----------------------------------------------------------------------\n");

	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_inodes_count",
		es.s_inodes_count,
		es.s_inodes_count,
		"Numero total de inodos, ocupados y disponibles");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_inodes_count",
		es.s_blocks_count,
		es.s_blocks_count,
		"Numero total de bloques, ocupados y disponibles");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_r_blocks_count",
		es.s_r_blocks_count,
		es.s_r_blocks_count,
		"Numero total de bloques reservados*/");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_free_blocks_count",
		es.s_free_blocks_count,
		es.s_free_blocks_count,
		"Numero de bloques libres");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_free_inodes_count",
		es.s_free_inodes_count,
		es.s_free_inodes_count,
		"Numero de inodos libres");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_first_data_block",
		es.s_first_data_block,
		es.s_first_data_block,
		"Primer bloque de datos disponible");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_log_block_size",
		es.s_log_block_size,
		es.s_log_block_size,
		"Logaritmo de tamaño de bloques");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_blocks_per_group",
		es.s_blocks_per_group,
		es.s_blocks_per_group,
		"Bloques por grupo de bloques");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_inodes_per_group",
		es.s_inodes_per_group,
		es.s_inodes_per_group,
		"Inodos por grupo");
/*	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_mtime",
		es.s_mtime,
		es.s_mtime,
		"-");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_wtime",
		es.s_wtime,
		es.s_wtime,
		"-");*/
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_mnt_count",
		es.s_mnt_count,
		es.s_mnt_count,
		"Numero de veces montado");/* s_mnt_count */
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_max_mnt_count",
		es.s_max_mnt_count,
		es.s_max_mnt_count,
		"Numero maximo de veces que puede ser montado");/* s_max_mnt_count */
	printf("%s\t %.20x\t %20.20x\t %20.80s\t\n",
		"s_magic",
		es.s_magic,
		es.s_magic,
		"Numero 'magico' identificador");/* s_magic */
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_state",
		es.s_state,
		es.s_state,
		"Estado");/* s_state */
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_errors",
		es.s_errors,
		es.s_errors,
		"Errores");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_minor_rev_level",
		es.s_minor_rev_level,
		es.s_minor_rev_level,
		"Rev level");
/*	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_lastcheck ",
		es.s_lastcheck ,
		es.s_lastcheck ,
		"Ultima comprovacion");*/
/*	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_checkinterval",
		es.s_checkinterval,
		es.s_checkinterval,
		"Intervalo entre comprovaciones");*/
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_creator_os",
		es.s_creator_os,
		es.s_creator_os,
		"Sistema operativo en el que fue creado");
	printf("%s\t %.20d\t %20.20d\t %20.80s\t\n",
		"s_rev_level",
		es.s_rev_level,
		es.s_rev_level,
		"Nivel de revision");
}

int main(int argc, char *argv[])
{
	char *volume = argv[1];
	printf("DEBUG %s\n", volume);
	analize_sb(volume);
	return 0;
}