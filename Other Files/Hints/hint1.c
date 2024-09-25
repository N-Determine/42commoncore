#include <stdio.h>
#include <stdlib.h>


void print_trans(char *str, int offset);

int main(void)
{
	char str[] = "Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe gur arkg pvepyr. Guvf punyyratr vf vaqvivqhny, gurer vf bayl n cevmr sbe bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf. Nal nqinagntrq crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur cevmr jvyy erznva flzobyvp. Gur uvag sbe guvf svefg cebwrpg vf: Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl hccre tenivgl ureb";
	print_trans(str, 13);
}

void print_trans(char *str, int offset)
{
	int i = 0;
	
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (((str[i] - 97) + offset) % 26) + 97;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (((str[i] - 65) + offset) % 26) + 65;
		i++;
	}
	printf("%s\n", str);
	i = 0;
}
