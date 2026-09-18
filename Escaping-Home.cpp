#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

struct game{
	char direction = ' ';
	string place = "livingRoom";
	bool over = false;              // becomes true when an ending is reached

	// rooms visited (used to pick the first-visit text)
	bool livingRoom = false;
	bool kitchen = false;
	bool bathroom = false;
	bool hallway = false;
	bool office = false;
	bool bedroom = false;

	// tasks
	bool blanketPillows = false;
	bool cups = false;
	bool dishes = false;
	bool dinner = false;
	bool bed = false;
	bool clothes = false;

	// distractions
	bool playGame = false;
	bool tv = false;
	bool shower = false;
};

void rules();
void start(game &gp);
void dirItemLook(game &gp);
void direction(game &gp);
void wrongDir();
void changePlace(game &gp);
void item(game &gp);
void look(game &gp);
void activity(game &gp);
void perform(game &gp, const string &name);
void checkEndings(game &gp);

void livingRoom(game &gp);
void kitchen(game &gp);
void hallway(game &gp);
void office(game &gp);
void bedroom(game &gp);
void bathroom(game &gp);

void leaveApartment(game &gp);
void napEnding(game &gp);
void tasksEnding(game &gp);
void distractionsEnding(game &gp);
void end(game &gp);

// ---------- input / output helpers ----------

string readLine(){
	string s;
	if(!getline(cin, s)){
		exit(0);   // input closed
	}
	return s;
}

string cleanText(string s){
	// trim whitespace and make lowercase
	size_t first = s.find_first_not_of(" \t\r\n");
	if(first == string::npos){
		return "";
	}
	size_t last = s.find_last_not_of(" \t\r\n");
	s = s.substr(first, last - first + 1);
	transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c); });
	return s;
}

char readChar(){
	string s = cleanText(readLine());
	if(s.empty()){
		return '\0';
	}
	return s[0];
}

bool yesNo(const string &prompt){
	while(true){
		cout<<prompt;
		char c = readChar();
		cout<<endl;
		if(c == 'y'){
			return true;
		}
		if(c == 'n'){
			return false;
		}
		cout<<"Please enter y (yes) or n (no)."<<endl<<endl;
	}
}

void say(const string &text){
	cout<<text<<endl<<endl;
}

// ---------- main ----------

int main(){
	game play;
	rules();
	start(play);
	return 0;
}

void rules(){
	cout<<"To play \"Escaping Home\" properly, there are a few rules you must know. If the game prompts you with a yes or no question, please enter y (yes) or n (no). If the game prompts you with a direction choice, please enter l (left), f (forward), r (right), or b (backwards). When you see the statement \"Enter whether you would like to enter a direction(d) or do a task(t): \" please enter either d (direction) or t (task). When the game prompts you to enter a task, enter the number next to the task you want to do."<<endl;
	cout<<"WARNING: This game has hints of abuse that could be upseting for some players. Please play carefully."<<endl;
	cout<<"Enter 'p' to play: ";
	readLine();
	cout<<endl<<endl;
}

void start(game &gp){
	gp.place = "livingRoom";
	livingRoom(gp);
	dirItemLook(gp);
}

void dirItemLook(game &gp){
	while(!gp.over){
		cout<<"Enter whether you would like to enter a direction(d) or do a task(t): ";
		char choice = readChar();
		cout<<endl;
		if(choice == 'd'){
			direction(gp);
		}
		else if(choice == 't'){
			activity(gp);
		}
		else{
			cout<<"That is not a valid choice. Please pick again."<<endl<<endl;
		}
	}
}

void direction(game &gp){
	while(true){
		cout<<"Enter the direction you would like to go (l, f, r, or b): ";
		gp.direction = readChar();
		cout<<endl;
		if(gp.direction == 'l' || gp.direction == 'f' || gp.direction == 'r' || gp.direction == 'b'){
			break;
		}
		cout<<"That is not a valid choice. Please choose again."<<endl<<endl;
	}
	changePlace(gp);
}

void changePlace(game &gp){
	if(gp.place == "livingRoom"){
		if(gp.direction == 'r'){
			gp.place = "kitchen";
			kitchen(gp);
		}
		else if(gp.direction == 'f'){
			gp.place = "hallway";
			hallway(gp);
		}
		else if(gp.direction == 'b'){
			leaveApartment(gp);   // the front door is behind you
		}
		else{
			wrongDir();
		}
	}
	else if(gp.place == "kitchen"){
		if(gp.direction == 'b'){
			gp.place = "livingRoom";
			livingRoom(gp);
		}
		else{
			wrongDir();
		}
	}
	else if(gp.place == "bathroom"){
		if(gp.direction == 'b'){
			gp.place = "hallway";
			hallway(gp);
		}
		else{
			wrongDir();
		}
	}
	else if(gp.place == "hallway"){
		if(gp.direction == 'f'){
			gp.place = "bedroom";
			bedroom(gp);
		}
		else if(gp.direction == 'l'){
			gp.place = "bathroom";
			bathroom(gp);
		}
		else if(gp.direction == 'r'){
			gp.place = "office";
			office(gp);
		}
		else if(gp.direction == 'b'){
			gp.place = "livingRoom";
			livingRoom(gp);
		}
		else{
			wrongDir();
		}
	}
	else if(gp.place == "office"){
		if(gp.direction == 'b'){
			gp.place = "hallway";
			hallway(gp);
		}
		else{
			wrongDir();
		}
	}
	else if(gp.place == "bedroom"){
		if(gp.direction == 'b'){
			gp.place = "hallway";
			hallway(gp);
		}
		else{
			wrongDir();
		}
	}
}

void wrongDir(){
	cout<<"You can not go that direction unless you want to hit a wall. Please try again."<<endl<<endl;
}

void item(game &gp){
	cout<<"You have the current items:"<<endl;
	cout<<"(nothing yet)"<<endl<<endl;
}

// ---------- first-visit descriptions ----------

string firstDesc(const string &place){
	if(place == "livingRoom"){
		return R"~(As you step up to the door, you grab your keys from your pocket. You shift through your keys, trying to find the right one. Your keys slip, making a clanking noise as they hit the ground. You curse and bend down to scoop them up. Shifting through the keys again, you successfully find the right key to unlock the door. You slip the key into the door and turn it right, hearing a click as the door unlocks. You swing the door open and drop your bag to the left of the door, right in front of the closest door, and right under the key hooks on which you hang your keys. You turn to the rest of the living room. Perpendicular to where you stand is a light brown couch with a yellow blanket haphazardly tossed on it. Directly in front of the couch is a low black coffee table, which has a few cups on it. Around the coffee table are pillows that would normally be on the couch, but you had thrown them on the floor when you were trying to get comfy watching M*A*S*H* last night. Pushed against the wall in front of the couch is a low black TV stand which has a large black flat-screen TV on top of it and a gaming console, controllers, and TV remotes on the one shelf under the TV. Under the Couch and coffee table is a large square rug that is light in color with a bunch of darker-colored lines on it. You scan the wall of your living room, seeing a few pictures of scenery and cute animals that you had put up just to make the room look more lived in. In front of you is a short hallway where you can see three doorways, and to the right of the living room you see the archway that leads to the kitchen.)~";
	}
	if(place == "kitchen"){
		return R"~(You walk into a small room. The floor has white tiles, and the walls are covered in blue paint. Tucked into the right corner, across from the door, is a refrigerator with a few bills clipped onto the front with orange and green clips. The counter stretches along the entire right wall, starting at the fridge and breaking for a small black stove and a white sink that has dirty dishes piled in it and spills onto the counter next to it. Above the counter are light brown cabinets with dark silver handles. There is a small breakfast table pushed up against the middle of the left wall with 3 wooden chairs pushed in around it and a fourth chair pushed into the far left corner.)~";
	}
	if(place == "hallway"){
		return R"~(You stop as you reach the beginning of the hallway. The hallway has brown carpet flooring and white walls. It is just long enough to have three doors and the space in between the doors, but not long enough to hold any furniture or pictures on the small walls. From where you stand, you can see the bathroom mirror through the door on the left, part of a full bookshelf through the door on the right, and the end of the bed through the door ahead of you.)~";
	}
	if(place == "bathroom"){
		return R"~(You walk into the smallest room in the entire apartment. This floor is white tiles with white walls, making the room look super bright. To the right of you is a small sink with a cabinet under it, and in the cabinet, you know there are a bunch of cleaning supplies that you didn't know where else to put them. A large round mirror hangs above the small counter with a thin black rim on it. Right next to the sink is a toilet, and above the toilet is a towel folded and hanging up. On the left, covering the entire wall of the small room is a shower with a bathtub at the bottom, a shower-bath. There's a shower curtain covered in sea animals pushed to the side so that you can see into the shower to see the plethora of soaps and scrubs you have collected over the years.)~";
	}
	if(place == "office"){
		return R"~(A wall of floral scents hit you from the plethora of candles littered around the room. On the back wall is a small window to let in natural light. On either side of the tiny window are two white curtains that are tied back with white ribbons. Pushed under the window, just about the size of the window, is a wooden desk. The desk is plain, with no drawers or shelves. Two large computer monitors and a tower are placed on top of the desk. A keyboard and a mouse are placed in front of the monitors. All the electronics are dark, but you know that when you turn the computer on, everything, including the keyboard and mouse, will light up with bright colors. A comfortable, black gaming chair is in front of the desk, angled away from the desk like someone just got up. On the chair is a thick gray blanket, and under the desk is a dark green footrest. You can clearly tell that someone works from home. Along the left and right walls are black bookshelves filled with books, CDs, games, and little knick-knacks. Soft brown carpet mutes the sound of your footsteps as you take a step into the room.)~";
	}
	// bedroom
	return R"~(You walk into the dark room, running your hand along the wall looking for a light switch. The first thing you notice when the light is turned on is the bed in the left corner of the room, with the headboard pushed against the left wall and the end of the bed ending in the middle of the back wall. The bed has a dark bed frame with dark gray and dark green blankets pushed all across the bed. Clearly, someone had to fight the blankets when getting up that morning. The windows in this room are covered with blackout curtains. To the left of you, pushed up against the wall next to you is a dresser that has a large mirror sitting on top of it. Right next to it is a matching wardrobe. Both the dresser and wardrobe are open, and clothes are spilling out onto the floor and slowly creeping across the floor to the bed.)~";
}

void look(game &gp){
	// re-read the full description of the room you are standing in
	cout<<"You take a longer look around."<<endl<<endl;
	say(firstDesc(gp.place));
}

// ---------- rooms ----------

void livingRoom(game &gp){
	if(!gp.livingRoom){
		gp.livingRoom = true;
		say(firstDesc("livingRoom"));
	}
	else if(gp.blanketPillows && gp.cups){
		say("You walk into the living room, happy with your work as you look at the blanket folded on the back of the couch, pillows back on the couch, and a cleared-off coffee table.");
	}
	else{
		say("You walk into the cluttered living room. The comfy couch is calling your name, but you stand there deciding what you should do next.");
	}
}

void kitchen(game &gp){
	if(!gp.kitchen){
		gp.kitchen = true;
		say(firstDesc("kitchen"));
	}
	else if(gp.dishes){
		say("As you walk into the tiny area, your eyes scan the table, refrigerator, stove, and empty sink, and you smile with accomplishment at the clean area.");
	}
	else{
		say("As you walk into the tiny area, your eyes scan the table, refrigerator, stove... and the sink that still has dirty dishes spilling out of the sink onto the counter.");
	}
}

void hallway(game &gp){
	if(!gp.hallway){
		gp.hallway = true;
		say(firstDesc("hallway"));
	}
	else{
		say("You move yourself so you can see the bathroom on the left, the office on the right, the bedroom in front of you, and your back to the living room.");
	}
}

void bathroom(game &gp){
	if(!gp.bathroom){
		gp.bathroom = true;
		say(firstDesc("bathroom"));
	}
	else{
		say("You walk into the tiny room, wishing the bathroom was a lot bigger, and wishing you had a bathtub with some jets in it.");
	}
}

void office(game &gp){
	if(!gp.office){
		gp.office = true;
		say(firstDesc("office"));
	}
	else{
		say("You take in the dark furniture and strong candle smell as you stare down at the computer and very comfortable-looking gaming chair.");
	}
}

void bedroom(game &gp){
	if(!gp.bedroom){
		gp.bedroom = true;
		say(firstDesc("bedroom"));
	}
	else if(gp.bed && gp.clothes){
		say("You walk into the room, looking at the blackout curtains and nicely made bed. You're excited for when you get to tuck yourself under the covers and make a mess out of the blankets again.");
	}
	else{
		say("You walk into the messy room. You don't enjoy mornings either, so you understand why the room looks like this.");
	}
}

// ---------- activities (tasks and distractions) ----------

void activity(game &gp){
	vector<string> options;

	if(gp.place == "livingRoom"){
		if(!gp.blanketPillows) options.push_back("Pick up blanket and pillows");
		if(!gp.cups)           options.push_back("Pick up cups");
		if(!gp.tv)             options.push_back("Watch TV");
	}
	else if(gp.place == "kitchen"){
		if(!gp.dishes)         options.push_back("Clean dishes");
		if(!gp.dinner)         options.push_back("Make dinner");
	}
	else if(gp.place == "bedroom"){
		if(!gp.bed)            options.push_back("Make the bed");
		if(!gp.clothes)        options.push_back("Pick up clothes");
		options.push_back("Take a nap");
	}
	else if(gp.place == "bathroom"){
		if(!gp.shower)         options.push_back("Take a shower");
	}
	else if(gp.place == "office"){
		if(!gp.playGame)       options.push_back("Play game");
	}

	if(options.empty()){
		say("There is nothing left for you to do here.");
		return;
	}

	cout<<"Here are the things you can do here:"<<endl<<endl;
	for(size_t i = 0; i < options.size(); i++){
		cout<<i + 1<<". "<<options[i]<<endl;
	}
	cout<<endl<<"Enter the number of the task you would like to do: ";
	string choice = cleanText(readLine());
	cout<<endl;

	// the player enters the number shown next to the task
	int number = 0;
	bool allDigits = !choice.empty() && choice.size() <= 3;
	for(size_t i = 0; i < choice.size(); i++){
		if(!isdigit((unsigned char)choice[i])){
			allDigits = false;
		}
	}
	if(allDigits){
		number = atoi(choice.c_str());
	}

	if(number >= 1 && number <= (int)options.size()){
		perform(gp, options[number - 1]);
		checkEndings(gp);
	}
	else{
		say("That is not a valid number. Please pick a number from the list.");
	}
}

void perform(game &gp, const string &name){
	// ----- living room tasks -----
	if(name == "Pick up blanket and pillows"){
		gp.blanketPillows = true;
		say("You grab the yellow blanket and start to fold it. As you fold, your mind starts to wander. Your partner had gotten you this blanket on one of your first dates with them. You thought it was sweet at the time, but now those memories feel more numb than anything. You lay the blanket across the back of the couch and go to grab the pillows on the ground. As you pick them up, you have memories of your partner throwing them at you. The corner of your mouth twitches upward as you remember that they were upset at you for not having food done and were a little hangry that day. You finish putting the last pillow on the couch and stand back to take a look. The living room already looks a lot cleaner with the floor picked up.");
	}
	else if(name == "Pick up cups"){
		gp.cups = true;
		say("You sigh as you take a look at the table with the coffee cups. You had mentioned to your partner multiple times that it would be helpful if they put the cups in the sink to soak, but they never did. You grab the cups and set them next to the sink in the kitchen, knowing that you would have to clean them soon before your partner got home. You return back to the living room to see what to do next.");
	}
	// ----- kitchen tasks -----
	else if(name == "Clean dishes"){
		if(!gp.cups){
			say("You look at the large pile of dishes, but the cups from the living room coffee table still need to be brought in here first.");
			return;
		}
		gp.dishes = true;
		say("You look at the large pile of dishes. You hate doing dishes. But you hate the outcome of not doing them more. You pick up a pan you know you'll need for dinner and grumble as you see that it still has spaghetti sauce from two nights ago. You glance at the time on the stove and decide you don't have time to clean all the dishes, but if you can get it down to just the dishes in the sink, that should make it less harsh on you later. You roll up your sleeves and get to work on scrubbing the dishes of all the stains. As soon as you wash a dish, you dry it and put it up, knowing your partner doesn't like to see the dishes on the counter.");
	}
	else if(name == "Make dinner"){
		if(!gp.dishes){
			say("You can't cook in this mess. You need to get the dishes cleaned first.");
			return;
		}
		gp.dinner = true;
		say("You open the fridge to see the steak you had put in there earlier. You had seasoned it and started soaking it in some juices before you left for work earlier. Tonight is supposed to be a special night for you and your partner, and you're nervous you'll mess something up. Taking the steak out and setting it on the counter with one hand, you go to open the cabinet next to the fridge to take the potatoes out. This is your partner's favorite meal and requests it for all special nights. You take a deep breath, knowing that last time you made the meal wrong, they were upset for the rest of the evening. You can do this, you tell yourself. Knowing that if you wait any longer, you won't have time to finish, you start cooking the steak and chopping the potatoes. Once everything is prepped, you slide the potatoes into the oven and leave the steak covered off to the side, knowing it'll only take a few minutes to sear on the stove. You take a step back, ready to start on something else.");
	}
	// ----- bedroom tasks -----
	else if(name == "Make the bed"){
		gp.bed = true;
		say("You go to pull the blankets back in place, but, like every day, realize that the blankets have somehow gotten tangled up and tossed around enough that it would just be easier for you to drag all the blankets off the bed and fully remake the bed. As you remake the bed, sheet first, then blanket, you think about how your partner will not go to sleep until the bed is made. One time, they started to fall asleep on the couch out in the living room because you were getting home late and had forgotten to make the bed before you left. The next morning after that, your partner gave you a long lecture - sorry, \"conversation\" - on how you make the bed better, so you should do it before you go out late like that again. That wasn't the worst \"conversation\" you've had with your partner, but it was the first. Finishing up on smoothing the blanket down, you stand up and smile at the bed. It was one of your favorite places, and you would stay there all day if you could, but sadly there was more to be done.");
	}
	else if(name == "Pick up clothes"){
		gp.clothes = true;
		say("You look down at the clothes on the floor. Some of the clothes are yours from last night when your partner was trying to find you the right outfit. They wanted to go out to the bar with their friends and wanted you to go along with them, but ended up deciding that you could stay home because there was nothing \"sexy\" in your wardrobe. The rest of the clothes were your partner's when they were looking for their lucky shirt to go in last night. It was the shirt they wore on your first date, and they say the shirt makes their eyes pop in just the right way. You haven't seen them since last night, assuming they crashed with a friend last night, which wasn't uncommon anymore. You grab your clothes and throw them in the wardrobe, not caring where they land, and close the doors. You pick up their clothes and walk over to the bed to fold them in the specific way they want their clothes folded. Tucking the folded clothes back into the dresser drawers, you close the drawers and see what else you can do.");
	}
	// ----- distractions -----
	else if(name == "Play game"){
		gp.playGame = true;
		say("You click the on button on the computer and sit down in the gaming chair. This was your partner's computer, but they had one game downloaded on it for you to play in your free time. If they knew you were playing a game without the apartment cleaned, they would be upset. Looking at the time, you think to yourself that you could play a quick game for 30 minutes and should still have time to clean up before they get home. You set a 30-minute timer on the computer and start up your game, wanting to continue the castle build that you had started. You lose track of time, and before you know it, your timer is going off, making you jump in the chair. Feeling a little sad that you had to stop, you save your game and close everything out. You shut the computer down and stand up to go work on cleaning something.");
	}
	else if(name == "Watch TV"){
		gp.tv = true;
		say("You stare longingly at the TV. Your feet hurt after a long day at work, and you think a quick 20-minute episode of something would be a nice way to relax. You think you'll have enough time and relax just a little bit. You tell yourself that if you let your feet rest for a little bit, you'll be even faster afterwards. You nod to yourself because that sounded like a good idea. You grab the remote, sit down on the couch, and swing your feet up on the couch too.");
	}
	else if(name == "Take a shower"){
		gp.shower = true;
		say("You look at the tiny shower. You know you take long showers, especially when you play music to listen to. Typically, you would save taking a shower until after all the clean-up is done, but you know you need to wash your hair and don't want wet hair when your partner gets home. Plus, they would be happier if they knew you washed up before they got home instead of having to wait on you later. Deciding it would be a better decision to take a shower now rather than later, you turn the shower on. While you wait for the shower to heat up, you strip off your clothes and grab your phone from your pocket to turn on some music. You stick your hand in to test the temperature of the water, and when you find it already warm, you step in and close the curtain behind you. You know you have until the end of this album to finish your shower and still have time to clean the apartment. You make sure to focus on taking your shower, only breaking out to sing a few times, and end up getting done with your shower a song early. You turn the shower off and grab the towel hanging up. You dry off in the shower before you step out, knowing water on the floor can upset your partner. Wrapping the towel around you and grabbing your discarded clothes from the floor, you walk down the hallway into your bedroom. You throw your dirty clothes in the hamper and grab something nice from the wardrobe. You'll have to be careful cleaning to make sure you don't get anything on these clothes, but you don't want to change a second time and get more clothes dirty. Now that you've taken a shower, you feel a lot better, but you still have work to do.");
	}
	else if(name == "Take a nap"){
		say("You look at your favorite place in the apartment: the bed. Work was draining today, like most days, but today seemed to be especially brutal. And the thought of all the cleaning you had to get done was draining the last bit of energy you had. You know it's a bad idea, but the bed is calling to you.");
		if(yesNo("Are you sure you want to take a nap? (y/n): ")){
			napEnding(gp);
		}
		else{
			say("You decide it would be better to continue cleaning, and maybe if you get everything done before your partner gets home, you can take a quick nap then.");
		}
	}
}

void checkEndings(game &gp){
	if(gp.over){
		return;
	}
	if(gp.blanketPillows && gp.cups && gp.dishes && gp.dinner && gp.bed && gp.clothes){
		tasksEnding(gp);
	}
	else if(gp.playGame && gp.tv && gp.shower){
		distractionsEnding(gp);
	}
}

// ---------- endings ----------

void end(game &gp){
	cout<<"END"<<endl<<endl;
	gp.over = true;
}

void leaveApartment(game &gp){
	say("You look at the apartment door. You know you could walk out, but there's also still more stuff for you to do in the apartment. You take a look around the living room, thinking about all the memories you have here, but you also realize you don't have anything here that you feel like keeping. Some days you wish you could just throw everything away and start fresh. New couch, new rug, new pictures, new walls.... You look back at the door, debating your next decision.");
	if(yesNo("Do you leave the apartment? (y/n): ")){
		say("You reach for the door handle. There's nothing keeping you here, but there's nothing encouraging you to go either. You have no idea where you would go. You don't know anyone in the area except for your partner. Your partner always got jealous and angry when you would hang out with your friends, and at some point they stopped inviting you. You didn't push to keep that connection either because it was easier for you to just stay home. You look back at the living room. All the furniture in the apartment, your partner picked out, and the pictures that you put in the living room are the only thing you were allowed to put up. As you look around you slowly realize all those memories keeping you here were just your partner telling you what to do or telling you how you could never make it in this world without them. You start to feel upset and angry. Who are they to tell you what you can't do.\n\n\"I'll prove them wrong. I'll do what I want now.\" You take your phone and leave it on the table. Your partner had long ago demanded that they track your phone for \"safety purposes\" but refused to let you track them.\n\nYou grab the door handle and yank the door open. You walk your way out of the apartment building feeling lighter than you have in years. You have no idea where you'll go or what you'll do, but you know that you'll make it your life.");
		end(gp);
	}
	else{
		say("You decide there's too much to do here, and you don't even know where you would go. You turn back to the living room to decide what to do next.");
	}
}

void napEnding(game &gp){
	say("With the last of your will disappearing as you touch the cool sheets, you crawl into bed and pull the covers up to your chin. Just a few minutes, you think to yourself as you set a timer on your phone to wake up in 30 minutes. You close your eyes and almost immediately fall asleep.\n\n\"Wake up, what the hell are you doing?\" You feel your body being shaken awake.\n\nBolting upright, you snatch your phone and look at the time. It's been four hours since you fell asleep. Looking up from your phone, you see your partner looming over you.\n\n\"Where's dinner? Why is the apartment a mess? And I thought I told you to dress nice?\" Your partner looks like they were about to start into another long \"conversation.\"\n\n\"I'm sorry I set an alar-\"\n\n\"Tonight was supposed to be a nice night, and you ruined it again. Just like you always do,\" your partner huffs at you with a glare. Not knowing what to say, you keep quiet. \"Oh, and now you don't want to talk?\" They give you an expectant look, waiting for something.\n\n\"I-\"\n\n\"I don't even want to hear your excuses. It's my birthday, and I'm not letting your screw-up ruin my night.\" They rifle through their clothes and pull out a top and bottom that you only see them wear when they go to the bar. \"You can stay here and actually clean up, like you were supposed to.\" You curl your legs up into your chest and watch them move around the room getting ready to go out. \"I'll be out late, might not even be back tonight, so don't wait up for me.\" They slip their shoes on, and you hear them stomp down the hallway to the front door.\n\nYou hear the door slam shut and release a breath you didn't know you were holding. You lay your head on your knees and close your eyes. You know they won't be back tonight. You grab the blankets and lie down, pull the blankets over your head, and drift back to sleep, hoping that tomorrow will be better.");
	end(gp);
}

void tasksEnding(game &gp){
	say("Just as you finish your last task, you hear the front door open.\n\n\"I'm home!\" You hear your partner call out.\n\nYou walk up to them and give them a kiss on the cheek. \"How was work today?\" you ask as you take their jacket to hang up.\n\n\"It was fine, did you finish cleaning up?\" they ask as they kick their shoes off.\n\n\"Yes, I just finished and I have food started in the kitchen, you just have to let me know when you want the steaks done,\" you reply back as you pick up their shoes and move them out of the way.\n\n\"I'm gonna take a quick shower and then you can make the steaks. How about while I'm in the shower you change into something else. Wear that one outfit I like,\" they say as they walk to the bathroom.\n\nYou go change like they wanted and sear the steaks, setting the food on the table right as they walk into the kitchen.\n\n\"This looks great, hopefully you didn't overcook it like the last time you made steaks.\"\n\nAs you two eat, your partner tells you about their day and you sit quietly and listen.\n\n\"My friends want to take me out to the bar for my birthday tonight and since you've finished all the cleaning and got dressed up I think you should go with me,\" they tell you as you clean up the plates.\n\n\"Well I don't know, I'm really tired from working and cleaning-\"\n\n\"And you don't think I'm tired from work either? This is my birthday, you should want to celebrate me if you really loved me,\" they frown at you.\n\n\"Yes you're right. I'll go with you,\" you say with your back turned to them so they don't see the tears starting to form.\n\n\"No, nevermind. I don't want you to come along if you're not going to be excited to go. Just stay here and pout.\" They storm out of the room and you can hear the front door slamming closed.\n\nYou sigh to yourself and let a few tears fall. Even when you do everything right, you somehow do something wrong. You finish cleaning up the dishes and then decide that you'll go take that nap you wanted earlier. You take off the outfit your partner wanted you to wear and change into loose, comfy clothes. You always hate wearing that tight outfit, but your partner says it shows all the right stuff. Without anything else to do you tuck yourself into bed and hope tomorrow will be better.");
	end(gp);
}

void distractionsEnding(game &gp){
	say("Just as you were about to continue cleaning the apartment up, you hear the front door open. Crap! you think to yourself. I haven't finished cleaning up! They're gonna be so upset.\n\n\"I'm home!\" you hear them call out, \"and it looks like you haven't done anything productive today.\" They give you a disappointed look.\n\n\"I'm sorry I got distracted....\" you trail off.\n\n\"Yeah, clearly. All I asked you to do was clean up and make dinner. Is that so much to ask for?\" They take their shoes off and throw their jacket on the couch.\n\n\"No,\" you mumble quietly.\n\n\"Stop the mumbling, you know I hate it when you mumble. I'm gonna take a shower, and I'll deal with you when I get out.\"\n\nThe second you hear the bathroom door click closed, you rush to throw things into drawers and pick up the apartment. You're about to go into the kitchen to finish cleaning up and make food when your partner steps out of the bathroom. They take a look around and chuckle.\n\n\"Just because you threw things out of sight doesn't mean the apartment is clean. You'll have to redo everything you just did.\" You nod your head, unsure how to respond to that.\n\n\"Since you messed up my birthday dinner, you'll be staying here while my friends take me out to celebrate. They won't mess up my birthday.\"\n\n\"I can still make dinner, and it'll only take a minute for me to finish cleaning up,\" you try to make it up to your partner.\n\n\"No, no, no. You know it'll take longer than that, and if it really does take you a minute, then why would you not do it before I got home?\" They wait for a response, but you don't know anything to say that won't get them upset at you. \"Yeah, that's what I thought. Got nothing to say for yourself. Well, I'll be out late. Make sure to clean up while I'm gone. You ruined my birthday dinner. I don't want you ruining my mood when I get back, too.\" They slip their shoes on and leave the apartment. The fact that they didn't raise their voice or slam the door made you feel even worse. You wish they would have just screamed and stomped out like they normally do, the calm emotions they used made you really feel like you messed up big time.\n\nTaking a deep breath, you pull out everything you shoved aside and properly clean up the apartment the way your partner liked it. You look at the steak that was supposed to be for dinner. Maybe you can make that tomorrow for your partner to say sorry. As for the rest of your evening, you decide that you have no more energy for the day and tuck yourself into bed. At least that way you won't be awake to watch the clock tick by.");
	end(gp);
}
