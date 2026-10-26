Carefree_Village_MapScripts::
	.byte 0

// 👇 极简版送宝可梦脚本 👇
CarefreeVillage_EventScript_GiftCharmander::
	lock
	faceplayer
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, CarefreeVillage_EventScript_PartyFull
	
	checkflag FLAG_RECEIVED_CHARMANDER
	goto_if_set FLAG_RECEIVED_CHARMANDER, CarefreeVillage_EventScript_AlreadyReceived
	
	msgbox CarefreeVillage_Text_GiftCharmanderIntro, MSGBOX_DEFAULT
	
	// 👇 给 5 级火神蛾 👇
	givemon SPECIES_VOLCARONA,5, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	message CarefreeVillage_Text_ReceivedCharmander
	waitmessage
	waitfanfare
	
	// 👇 给共鸣石 👇
	additem ITEM_RESONANCE_STONE, 1
	message CarefreeVillage_Text_ReceivedStone
	waitmessage
	
	setflag FLAG_RECEIVED_CHARMANDER
	msgbox CarefreeVillage_Text_GiftCharmanderPost, MSGBOX_DEFAULT
	release
	end

// 队伍满了跳转
CarefreeVillage_EventScript_PartyFull::
	msgbox CarefreeVillage_Text_PartyFull, MSGBOX_DEFAULT
	release
	end

// 已经拿过了跳转
CarefreeVillage_EventScript_AlreadyReceived::
	msgbox CarefreeVillage_Text_AlreadyReceived, MSGBOX_DEFAULT
	release
	end

// 👇 文本区域 👇
CarefreeVillage_Text_GiftCharmanderIntro:
	.string "光头大叔：这只火神蛾，\n"
	.string "还有这块共鸣石，就交给你了！$"

CarefreeVillage_Text_ReceivedCharmander:
	.string "{PLAYER} 获得了火神蛾！$"

CarefreeVillage_Text_ReceivedStone:
	.string "{PLAYER} 获得了共鸣石！$"

CarefreeVillage_Text_GiftCharmanderPost:
	.string "光头大叔：把它练到 75 级，\n"
	.string "再用石头试试吧！$"

CarefreeVillage_Text_PartyFull:
	.string "光头大叔：你的队伍满了！\n"
	.string "先去电脑里存一只再来找我吧。$"

CarefreeVillage_Text_AlreadyReceived:
	.string "光头大叔：火神蛾就那一只，\n"
	.string "可别弄丢了啊！$"

// 👇 弗洛洛的对战脚本 👇
CarefreeVillage_EventScript_Fuluoluo::
	lock
	faceplayer
	// 这里直接开打，没有复杂的 Flag 判断
	msgbox CarefreeVillage_Text_FuluoluoIntro, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_FULUOLUO, CarefreeVillage_Text_FuluoluoIntro, CarefreeVillage_Text_FuluoluoDefeat
	// 打完之后的对话
	msgbox CarefreeVillage_Text_FuluoluoPost, MSGBOX_DEFAULT
	release
	end

// 👇 文本区域 👇
CarefreeVillage_Text_FuluoluoIntro:
	.string "弗洛洛：你就是那个新来的？\p"
	.string "我是残星会会监，让我看看你的实力！$"

CarefreeVillage_Text_FuluoluoDefeat:
	.string "弗洛洛：这不可能……\n"
	.string "你竟然破解了我的战术……$"

CarefreeVillage_Text_FuluoluoPost:
	.string "弗洛洛：看来，我需要重新评估你了。\n"
	.string "我们后会有期。$"
	