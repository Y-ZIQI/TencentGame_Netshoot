// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveObject.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "Misc/FileHelper.h"

void UMySaveObject::SaveGame(FString Name, int32 Score)
{
	IPlatformFile& F = FPlatformFileManager::Get().GetPlatformFile();
	if (!F.DirectoryExists(*FilePath))
	{
		F.CreateDirectoryTree(*FilePath);
		if (!F.DirectoryExists(*FilePath))
		{
			return;
		}
	}
	FString dir = FilePath + "save.txt";
	FString content;
	FFileHelper::LoadFileToString(content, &F, *dir);
	FFileHelper::SaveStringToFile(content + Name + "\n" + FString::FromInt(Score) + "\n", *dir);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, dir);
}

TArray<FString> UMySaveObject::LoadScore()
{
	TArray<FString> ScoreList;
	IPlatformFile& F = FPlatformFileManager::Get().GetPlatformFile();
	if (!F.DirectoryExists(*FilePath))
	{
		F.CreateDirectoryTree(*FilePath);
		if (!F.DirectoryExists(*FilePath))
		{
			return ScoreList;
		}
	}
	FString dir = FilePath + "save.txt";
	FString content;
	FFileHelper::LoadFileToString(content, &F, *dir);
	FString LeftS;
	FString RightS;
	if (content.Split("\n", &LeftS, &RightS) && !RightS.Equals("End")) {
		ScoreList.Add(LeftS);
		while (RightS.Split("\n", &LeftS, &RightS) && !RightS.Equals("End")) {
			ScoreList.Add(LeftS);
		}
	}
	return ScoreList;
}
