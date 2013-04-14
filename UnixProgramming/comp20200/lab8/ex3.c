#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void printOrderedTree(struct tnode *);
void OTprint(struct tnode *p,int max);
void treeprint(struct tnode *);
int getword(char *, int);

int count;

/* word frequency count */
int main()
{
count=0;
struct tnode *root;
char word[MAXWORD];
root = NULL;
while (getword(word, MAXWORD) != EOF)
if (isalpha(word[0]))
root = addtree(root, word);
treeprint(root);

int a;
for(a=count; a > 0 ; a--)
{
	OTprint(root,a);
}

return 0;
}


struct tnode
{    /* the tree node: */
	char *word;          /* points to the text */
	int count;            /* number of occurrences */
	struct tnode *left;  /* left child */
	struct tnode *right;  /* right child */
};

struct tnode *talloc(void);
//char *strdup(char *);
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	if (p == NULL)
	{      /* a new word has arrived */
		p = talloc();    /* make a new node */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;      /* repeated word */
	else if (cond < 0)    /* less than into left subtree */
		p->left = addtree(p->left, w);
	else              /* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) 
	{
		treeprint(p->left);
		if(p->count > count)
		{
			count = p->count;
			//printf("%d\n",count);
		}
		//printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* Ordered print: in-order print of numbers in the node of the tree p */
void OTprint(struct tnode *p,int max)
{
	if (p != NULL) 
	{
		OTprint(p->left,max);
		if(p->count == max)
		{
			printf("%4d %s\n", p->count, p->word);
		}
		OTprint(p->right,max);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* char *strdup(char *s)  // make a duplicate of s
{
char *p;
p = (char *) malloc(strlen(s)+1); // +1 for '\0'
if (p != NULL)
strcpy(p, s);
return p;
}
*/

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	while (isspace(c = getch()));
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) 
	{
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) 
		{
			ungetch(*w);
			break;
		}
		*w = '\0';
	return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;          /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)    /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
