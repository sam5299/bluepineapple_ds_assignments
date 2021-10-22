#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char data[30];
	struct node* next;
};

void appendBook(void);
void showBooks(void);
int count(void);
int searchBook(char[]);
void deleteBook(int);
struct node* head = NULL;
int len;
void main(){
	int option;
	int loop = 1;
	int position;
	char bookToSearch[30];
	while(loop){
		printf("\nSelect option from book management:");
		printf("\n1.Add book");
		printf("\n2.View Books");
		printf("\n3.total  Book");
		printf("\n4.Search Book");
		printf("\n5.Delete Book");
		printf("\n0.Exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				appendBook();
				break;
			case 2:
				showBooks();
				break;
			case 3:
				len = count();
				printf("total no of books:%d",len);
				break;
			case 4:
				printf("\nEnter bookname to search:");
				scanf("%s",bookToSearch);
				position = searchBook(bookToSearch);
				break;
			case 5:
				printf("\nEnter bookname to search:");
				scanf("%s",bookToSearch);
				position = searchBook(bookToSearch);
				if(position>0){
					deleteBook(position);
				}
				break;
			case 0:
				loop = 0;
				break;
			default:
				break;	
		}
	}
}

void appendBook(){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter name of book:");
	scanf("%s",&temp->data);
	temp->next = NULL;
	if(head==NULL){
		head = temp;
	}
	else{
		struct node* traverseAppend;
		traverseAppend = head;
		while(traverseAppend->next!=NULL){
			traverseAppend = traverseAppend->next;
		}
		traverseAppend->next = temp;
	}
}

void showBooks(){
	int count = 0;
	struct node* temp;
	temp = head;
	if(temp == NULL){
		printf("\nSorry no books available.");
	}
	else{
		printf("\n\nBelow are available books \n\n");
		while(temp!=NULL){
		printf("\n%s",temp->data);
		temp = temp->next;
		count++;
		}
		printf("\nTotal books present:%d\n",count);
	}
	printf("\n\n");
}

int count(){
	int count = 0;
	struct node* temp;
	temp = head;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

int searchBook(char bookname[]){
	struct node* temp;
	int count = 0;
	int found = 0;
	temp = head;
	if(head==NULL){
		printf("\nLibrary having 0 books.");
		return 0;
	}
	else{
		while(temp!=NULL){
		if(strcmp(temp->data,bookname)==0){
			found = 1;
			printf("\nBook is available:");
			count++;
			break;
		}
		temp = temp->next;
		count++;
		}
	}
	if(found==0){
		printf("\nBook not present.");
		return 0;
	}
	return count;
}

void deleteBook(int position){
	len = count();
	struct node *toDelete, *prevNode;
	int i;
	toDelete = head;
	if(position==1){
		toDelete = head;
        head = head->next;
        printf("\nbook deleted = %s\n", head->data);
        free(toDelete);
	}
	else if(position==len){
		toDelete = head;
        prevNode = head;

        while(toDelete->next != NULL)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            prevNode->next = NULL;
        }

        printf("Deleting %s",toDelete->data);
        free(toDelete);
	}
	else{
		toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;

			printf("Deleting %s",toDelete->data);
            /* Delete nth node */
            free(toDelete);
        }
        else
        {
            printf("Invalid position unable to delete.");
        }

	}
}
