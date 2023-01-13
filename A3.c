#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char s[100];
int top = -1;

// Initializing Struct:
typedef struct tree
{
    char x[15];
    struct tree *right;
    struct tree *left;
    struct tree *next;
} tree;

struct tree *head = NULL;

void push(char x);
char pop();
int priority(char x);
char *seperateString(char *String);
struct tree *newBranch(char x[15]);
struct tree *popTree();
void pushToTree(struct tree *tree);
void printTree(struct tree *tree);
void printPreorder(struct tree *tree);
void printPostorder(struct tree *tree);

int main(int argc, char *argv[])
{
    struct tree *L;
    struct tree *R;
    struct tree *new;
    char *str, x;
    str = argv[1];
    int playerChoice = 0;
    int length = 0;
    int i = 0;
    char *str2 = malloc(strlen(str) + 1);
    char tempString_One[15] = " ";
    char tempString_Two[15] = " ";
    char tempString_Three[15] = " ";

    //Putting string into post order (so we can then store in binary tree):
    while (*str != '\0')
    {
        //Checks if character is a letter (i.e. for x1, x2, x3) :
        if (isalpha(*str))
        {
            str2[length] = *str;
            length++;
            str++;
            str2[length] = *str;
            length++;
        }
        //Checks if character is digit (if it is we know next 3 are part of that digit as well):
        else if (isdigit(*str))
        {
            str2[length] = *str;
            length++;
            str++;
            str2[length] = *str;
            length++;
            str++;
            str2[length] = *str;
            length++;
            str++;
            str2[length] = *str;
            length++;
        }
        else if (*str == '(')
            push(*str);
        else if (*str == ')')
        {
            while ((x = pop()) != '(')
            {
                str2[length] = x;
                length++;
            }
        }
        else
        {
            while (priority(s[top]) >= priority(*str))
            {
                str2[length] = *str;
                length++;
            }
            push(*str);
        }
        str++;
    }
    while (top != -1)
    {
        x = pop();
        str2[length] = x;
        length++;
    }

    str2[length] = '\0';

    while (i < strlen(str2))
    {
        // If sign = character -> start a new string:
        if (str2[i] == '-' || str2[i] == '+' || str2[i] == '/' || str2[i] == '*')
        {
            tempString_One[0] = str2[i];
            tempString_One[1] = '\0';
            new = newBranch(tempString_One);

            R = popTree();
            L = popTree();

            new->left = L;
            new->right = R;

            pushToTree(new);
            i++;
        }
        // If its therefore a variable (x1,x2,x3) then get number in front of "x", assign it to a temp string and create new node:
        else if (str2[i] == 'x' || str2[i] == 'X')
        {
            tempString_Two[0] = str2[i];
            tempString_Two[1] = str2[i + 1];

            // Null character (to end temp string):
            tempString_Two[2] = '\0';
            new = newBranch(tempString_Two);
            pushToTree(new);
            i += 2;
        }
        //Checking if character is a float (manually), and assigning it to a temp string to be pushed if it is:
        else if (isdigit(str2[i]) && str2[i + 1] == '.')
        {
            tempString_Three[0] = str2[i];
            tempString_Three[1] = str2[i + 1];
            tempString_Three[2] = str2[i + 2];
            tempString_Three[3] = str2[i + 3];
            // Null character (to end temp string):
            tempString_Three[4] = '\0';

            new = newBranch(tempString_Three);
            pushToTree(new);

            i += 4;
        }
    }

    // MENU:
    while (playerChoice != 3)
    {

        printf("Please Select a Menu Option:\n\n");
        printf("1.Preorder\n\n");
        printf("2.Postorder\n\n");
        printf("3. Exit\n\n");

        scanf("%d", &playerChoice);

        if (playerChoice == 1)
        {
            printf("\n\n\n\nPREORDER: ");
            printPreorder(new);
            printf("\n\n\n\n");
        }
        else if (playerChoice == 2)
        {
            printf("\n\n\n\nPOSTORDER: ");
            printPostorder(new);
            printf("\n\n\n\n");
        }
        else if (playerChoice == 3)
        {
            printf("\n\nGoodbye :)!\n\n");
            free(str2);
            break;
        }
        else
        {
            printf("\n\n\n\nOPTION INVALID! PLEASE TRY AGAIN\n\n\n\n");
        }
    }
    return 0;
}


// Creating Helper Fcn:
struct tree *newBranch(char x[15])
{
    // Creating space for tree:
    struct tree *tree = (struct tree *)malloc(sizeof(struct tree));

    // Defining node elements:
    strcpy(tree->x, x);
    tree->right = NULL;
    tree->left = NULL;
    tree->next = NULL;

    return (tree);
}

//Function for pushing to tree:
void pushToTree(struct tree *top)
{

    // setting current node pushed as head if empty:
    if (head == NULL)
    {
        head = top;
    }
    else
    {
        (top)->next = head;
        head = top;
    }
}

//Function for popping from tree:
tree *popTree()
{
    tree *test = head;
    head = head->next;
    return test;
}

void push(char x)
{
    s[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return s[top--];
}

//Priority function used to make sure string empty:
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void printTree(struct tree *tree)
{
    // checking if NULL then exiting if true (void cannot return anything):
    if (tree == NULL)
    {
        return;
    }
    else
    {
        // Going to the left branch (recursion #1):
        printTree(tree->left);

        // Printing Data of Node:
        printf("%s", tree->x);

        // Going to the right branch (recursion #2):
        printTree(tree->right);
    }
}

void printPreorder(struct tree *tree)
{
    // Checking to see if tree is NULL
    if (tree == NULL)
    {
        return;
    }

    // Print node data
    printf("%s ", tree->x);
    // Left branch recursion
    printPreorder(tree->left);
    // Right branch recursion
    printPreorder(tree->right);
}

void printPostorder(struct tree *tree)
{
    // Checking to see if tree is NULL
    if (tree == NULL)
    {
        return;
    }

    // Left branch recursion
    printPostorder(tree->left);
    // Right branch recursion
    printPostorder(tree->right);
    // Print node data
    printf("%s ", tree->x);
}