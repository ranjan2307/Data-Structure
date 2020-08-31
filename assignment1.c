#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char name[20];
    int goals;
    char club[20];
    struct node *next;
} Node, *newP;

newP head;

newP create(int goals, char name[], char club[])
{
    newP new = (newP)malloc(sizeof(Node));
    new->next = NULL;
    strcpy(new->name, name);
    strcpy(new->club, club);
    new->goals = goals;
    return new;
}

void insertbeg(int goals, char name[], char club[])
{
    newP new = create(goals, name, club);
    if (head == NULL)
        head = new;
    else
    {
        new->next = head;
        head = new;
    }
}

void del(char name[])
{
    newP temp = head;
    if (head == NULL)
        return;

    if (!strcmp(temp->name, name))
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        while (strcmp(temp->next->name, name))
            temp = temp->next;
        newP to_free = temp->next;
        temp->next = temp->next->next;
        free(to_free);
    }
}
void display()
{
    if (head == NULL)
        printf("EMPTY LIST");
    else
    {
        newP temp = head;
        while (temp != NULL)
        {
            printf("[%s,%s,%d]  ", temp->name, temp->club, temp->goals);
            temp = temp->next;
        }
    }
}

void search_node(char name[])
{
    newP temp = head;
    if (head == NULL)
        return;
    int flag = 0, pos = 1;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("%s found at position: %d \n", name, pos);
            flag = 1;
        }
        pos++;
        temp = temp->next;
    }
    if (flag == 0)
        printf("Player not found\n");
}

void count_nodes()
{
    newP temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes are %d\n", count);
}

void avg()
{
    newP temp = head;
    int sum = 0, count = 0;
    while (temp != NULL)
    {
        count++;
        sum += temp->goals;
        temp = temp->next;
    }
    float aveg = (float)sum / count;
    printf("Average goals: %f\n", aveg);
}

int main()
{
    int ch, goal, nxt, pos;
    char name[20], club[20], car;
    int num;

    //Insertion Beginning
    printf("\nEnter number of nodes to be inserted at beginning:");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {

        printf("\nNode-%d\nEnter the Goals: ", i + 1);
        scanf("%d", &goal);
        printf("Enter the Name: ");
        scanf("%s", name);
        printf("Enter the Club: ");
        scanf("%s", club);
        insertbeg(goal, name, club);
        printf("\n");
        display();
        printf("\n");
    }

    //Deletion
    printf("\nEnter number of nodes to be deleted:");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("\nDelete operation:%d\nEnter the name to be deleted : ", i + 1);
        scanf("%s", name);
        del(name);
        printf("\n");
        display();
        printf("\n");
    }
    //Search
    printf("\nEnter number of nodes to be searched:");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("\nEnter the name to be Searched : ");
        scanf("%s", name);
        search_node(name);
    }
    printf("\n");
    count_nodes();
    avg();
    return 0;
}
