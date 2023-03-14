#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 280
/**
 * main - Entry point
 * Description: Twitter Tweet validator
 * Return: 0
 */
bool valid_tweet(char tweet[]);

int main(void)
{
	char tweet[MAX_LEN + 1];

	printf("Enter your tweet: ");
	scanf("%280[^\n]", tweet);

	if (valid_tweet(tweet))
	{
		printf("Valid tweet.\n");
	}
	else
	{
		printf("Invalid tweet.\n");
	}
	return (0);
}

/**
 * valid_tweet - Entry point
 * Description: Valid tweet checker
 * @tweet: Character
 * @MAX_LEN: Integer
 * Return: bool
 */

bool valid_tweet(char tweet[])
{
	int i;
	char c;

	if (strlen(tweet) > MAX_LEN)
	{
		return (false);
	}
	for (i = 0; i < strlen(tweet); i++)
	{
		c = tweet[i];
		if (c == '@' || c == '\n')
		{
			/* Check for invalid characters */
			printf("Contains @ mention\n");
			return (false);
		}
		if (c == 'h' && i < strlen(tweet) - 3 && strncmp(tweet + i, "http", 4) == 0)
		{
			/* Check URL */
			printf("Contains link\n");
			return (false);
		}
		if (i < strlen(tweet) - 3 && strncmp(tweet + i, "www", 3) == 0)
		{
			/* Check www */
			printf("Contains lin\nk");
			return (false);
		}
		if (i < strlen(tweet) - 4 && strncmp(tweet + i, ".com", 4) == 0)
		{
			/* Check .com */
			printf("Contains link\n");
			return (false);
		}
		if (i < strlen(tweet) - 1 && c == ':' && tweet[i + 1] == '/')
		{
			/* Check for other types of URL using / */
			return (false);
		}
	}
	return (true);
}
