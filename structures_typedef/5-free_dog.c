#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
 * free_dog - Libère la mémoire allouée pour un objet de type `dog_t`.
 * @d: Pointeur vers l'objet `dog_t` à libérer.
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		if (d->name != NULL)
		{
			free(d->name);
		}
		if (d->owner != NULL)
		{
			free(d->owner);
		}
		free(d);
	}
}
