// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/FoodItem.h"

#include "InventoryComponent.h"
#include "InventorySystemCharacter.h"

void UFoodItem::Use(AInventorySystemCharacter* Character)
{
	if(Character)
	{
		Character->Health+=HealthToHeal;

		if(OwningInventory)
		{
			OwningInventory->RemoveItem(this);
		}
	}
}
