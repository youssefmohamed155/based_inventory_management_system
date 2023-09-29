//
//  Inventory_Management_System.c
//  Inventory Management System
//
//  Created by Youssef on 17/09/2023.
//
// it's my second project :) ;
//
// printf - scanf - if - loop - function - pointer - Arra - string - stcure
//
#include "Inventory_Management_System.h"
#include "I _M _S.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
////=============================== < struct Add > =========================== :)
struct Product {
    int price;
    int quantity;
    char taxonomy[100];
    char name[100];
};
//==========================================================================================
struct Product * inventory; // addres any  sturct  of product
struct Product group[100];
int totalProducts = 0 ;
//......
ui16 PASW (void);
void min (void);
void addNewProducts(struct Product group[], int total);
void calculateTotalValue(struct Product group[], int total);
//void updateQuantities ( struct Product group[], int total);
void Update_Quantities ( struct Product group[], int total);
void printInventory(struct Product * inventory);

////========================================== < main >================================================

int main(int argc, const char * argv[]) {      // :)
    // insert code here...

    //===========================================================================
    printf("\n******************************************************************* \n");
    printf("  ----- program to manage an inventory of products in a store . -----\n");
    printf("********************************************************************** \n");
    //===========================================================================
   
    if (!PASW()) {
        printf("Incorrect password. Exiting the program.\n");
        return 0;
    }
    min ();
//Update();
    // Initialize pointers
    inventory = malloc(sizeof(struct Product));
    totalProducts = 0;
    return 0;
}

//      =========================== function PASW =========================== :)

ui16 PASW(void)
{
    int pwd = 12345;
    int j ;
    int password;
    int i;
//
//    int letterCount = 0;
//    int u = 0;
//    int totlee;

    printf("  Please enter the password: ");
    scanf("%d", &password);
    
//    while (password[u]!= NULL)
//    {
//        if (isalpha(password[u] != 0))
//        {
//
//            letterCount++;
//
//        u++;
//    }
//
//    totlee = letterCount ;
//
//    for (i = 0; i < totlee; i++)
//    {
//        printf("*");
//    }
//
//    //
    

    if (password == pwd)
    {
        printf("                    ---------- welcam in the app ---------- \n");
    }

    for(j=0; j<4; j++ )
            {

                if (password != pwd )
                {
                printf(" Password is wrong [%d], please return the password.... :  ",4-j);
                scanf("%d",&password);
                if (j == 3)
                {
                    printf(" This is the last attempt you have to focus on the password.. :");
                    scanf("%d",&password);
                }
                if (j == 4)
                {
                    break;
                }

      }

   }

    
return (1);
}


//    //         ===========================  function min =========================== :)

    void min (void)

{
        
        int chose;
        while (1)
        {
            printf("       [1] Add New Products. \n");
            printf("       [2] Update .\n");
            printf("       [3] calculate the total value of the inventory [CTVI].\n");
            printf("       [4] print Inventory.\n");
            printf("       [0] Eixt.\n");
            printf("\n  pleass write what's options Need : ");
            scanf("%d",&chose);

            if (chose < 5)
            {
                switch (chose) {
                    case 1:
                        printf("------------------------------------------------------------------\n");
                        addNewProducts(group, totalProducts); // &group[0]
                        break;
                    case 2:
                        printf("------------------------------------------------------------------\n");
                        Update_Quantities(group,totalProducts);

                        break;
                    case 3:
                        printf("------------------------------------------------------------------\n");
                        calculateTotalValue(group, totalProducts);

                        break;
                    case 4:
                        printf("------------------------------------------------------------------\n");
                        printInventory(&group[0]); // = (group)
                        break;

                    case 0:
                        printf("           Thank you for using the app      .\n");
                        return ;

                }


            }
            else if (chose > 5)
            {
                printf("--------------------------------------------\n");
                printf(" plaess Choose from the numbers [1 : 4] \n");
                printf("--------------------------------------------\n");

            }

        }
    }
    // =========================== function Add_New_Products =========================== :)
//

void addNewProducts(struct Product group[] , int total) // = *group
{
    int quantity;
    
    printf("\n - Number of products to add: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < quantity; i++)
    {
        printf(" Product #%d\n", total + i +1);
        
        printf(" Enter name: ");
        scanf("%s", group[total + i].name);
        
        printf(" Enter price: ");
        scanf("%d",& group[total + i].price);
        
        printf(" Enter quantity: ");
        scanf("%d",& group[total + i].quantity);
        
        printf(" Enter taxonomy: ");
        scanf("%s", group[total + i].taxonomy);
        
        printf("----------------------------------------------\n");
    }
    
    total += quantity;
    totalProducts = total ;
    printf("\n -> The data you entered: \n\n");
    
    for (int i = total - quantity; i < total; i++) {
        printf("  Product [%d]\n", i + 1);
        printf("    Name     : %s\n", group[i].name);    //storge
        printf("    Price    : %d\n", group[i].price);
        printf("    Quantity : %d\n", group[i].quantity);
        printf("    Taxonomy : %s\n", group[i].taxonomy);
        printf("----------------------------------------------\n");
    }
}

 //storge data :)

 // print the data ??? :)


   // ================================== function CTVI =========================== :) done

void calculateTotalValue(struct Product group[], int total)
{
    int totalValue = 0;
    
    for (int i = 0; i < total; i++)
    {
        totalValue += group[i].price * group[i].quantity;
        
           }
    printf("\n Total value of the inventory: %d \n", totalValue);
    printf("----------------------------------------------\n");
}

// // =========================== function Update Quantities ===========================

void Update_Quantities ( struct Product group[], int total)
{
    int anser ;
    int flag = 0;
    int newQuantity ;
    int new_piace ;
    char new_name [100];
    char taxonomy [100];
    char name [100] ;
    

    
    while (1) {
        printf(" what's Name  : ");
        scanf("%s",name);
        printf(" what's Taxonomy : ");
        scanf("%s",taxonomy);
        
        
        
        
        for (int i = 0; i < total; i++) {
            //|| strcmp((inventory)->taxonomy,taxonomy) == 0
            
            if (0  == strcmp(group[i].name, name)) // group[i]  ***
            {
                flag = 1;
                
                printf(" Do U Updata ? [1]Yas or [2] No : ");
                scanf("%i",&anser);
                
                if (anser == 1)
                {
                    
                    printf(" Product #%d\n", i +1); /// delete total
                    printf("\n Enter New  Name : ");
                    scanf("%s",new_name);
                    strcpy( group[i].name,new_name); // group[i]*** strcopy (new , old)
                    strcpy( group[i].taxonomy,taxonomy); // ***
                    
                    
                    printf(" Enter New price: ");
                    scanf("%i",& new_piace);
                    group[i].price = new_piace ;  // group[i]**
                    
                    printf(" Enter New quantity : ");
                    scanf("%d", &newQuantity);
                    group[i].quantity = newQuantity ;// group[i]**
                    printf("\n Quantity updated successfully.\n");
                    printf("----------------------------------------------\n");
                    
                    
                }
                
                
                
                else if (anser == 2)
                {
                    printf(" The update was successfully completed..\n");
                    // print the updata ???
                    printf("you Update : ");
                    printf("\nNew  Name     :  %s \n", group[i].name);
                    printf("  New  price    :  %d \n", group[i].price);
                    printf("  New  quantity :  %d \n",group[i].quantity);
                    printf("--------------------------n");
                    
                }

                else
                {
                    
                    printf("                     ********* Invalid Choice ********* \n");
                    printf("             ********* Please Choose the right action ********* \n");
                    
                }
            } // if

        } // for
    if(flag == 0)
        {
            printf("   Product not found ......\n");
            printf("----------------------------------------------\n");
        }
        
        int x;
        printf("do u want to make any other updates?  [1]Yes  [2]No \n");
        scanf("%d",&x);
        if (x  == 2)
            break;
        
    } // whlie
    for (int i = 0; i < total; i++)
    {

    }
} // fun
    

//===================================== print Inventory ====================================

void printInventory(struct Product * inventory)
{

        printf("\n      Inventory:    \n");
    
        for(int i=0; i<totalProducts; i++) {
        printf("Product #%d: \n", i+1);
            
        printf("Name: %s\n", inventory[i].name); // = gruop [i]
        printf("Price: %d\n", (inventory+i)->price); //= inventory[i].name
        printf("Quantity: %d\n",(inventory+i)->quantity);  // addes var -> name
        printf("Taxonomy: %s\n",(inventory+i)->taxonomy);
        printf("--------------------\n");
   
    }
    printf("----------------------------------------------\n");

}
