// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultItemDataStruct.h"

FItemDataStruct::FItemDataStruct() {
	Name = FName("Can be anything doesn't matter.");
	BackpackSocketName = FName("Don't leave this blank for the love of god.");
}

FItemDataStruct::~FItemDataStruct()
{
}
