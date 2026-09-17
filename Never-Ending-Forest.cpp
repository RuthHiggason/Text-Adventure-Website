//choose your own adventure
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//structs
struct gamePlay{
    string player;
    char direction;
    string place;
    bool cabin = false;
    bool bedroom = false;
    bool mountain = false;
    bool waterfall = false;
    bool berryClearing = false;
    bool woods = false;
    bool coin = false;
    bool axeAndPickAxe = false;
    bool sticks = false;
    bool rocks = false;
    bool fish = false;
    bool berries = false;
    bool berryOrWoods = false;
    bool bear = true;
};

//prototypes
void gameRules();
void startGame(gamePlay gp);
void placeChange(gamePlay gp);
void cabin(gamePlay gp);
void mountain(gamePlay gp);
void waterfall(gamePlay gp);
void berryClearing(gamePlay gp);
void woods(gamePlay gp);
void berryOrWoods(gamePlay gp);
void wrongDir(gamePlay gp);
void gameEndings();
void direction(gamePlay gp);
void useItem(gamePlay gp);
void bedroom(gamePlay gp);
void directionOrItem(gamePlay gp);
void clearing(gamePlay gp);
void allTasksDone();

int main()
{
    //variables
    gamePlay playing;
    
    //print out title of game
    cout<<setw(51)<<"The Never Ending Forest"<<endl;
    cout<<setw(52)<<"Can you find your way out?"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl<<endl;
    //prints out game rules
    gameRules();
    //start game
    startGame(playing);
    return 0;
}

//prints out rules for game
void gameRules(){
    char holder;
    cout<<"To play \"The Never Ending Forest\" properly, there are a few rules you must know. If the game prompts you with a yes or no question, please enter y (yes) or n (no). If the game prompts you with a direction choice, please enter l (left), f (forward), r (right), or b (backwards). When you see the statement \"Enter direction or item: \" please enter either d (direction) or i (item). When the game prompts you to enter an item, enter the full name of the item like it shows on the screen."<<endl;
    cout<<"Please enjoy your journey in the \"Never Ending Forest.\" Hope you can find the end!"<<endl;
    cout<<"Enter \'p\' to start your adventure: ";
    cin>>holder;
    cout<<endl<<endl;;
}

//starts the game in the clearing
void startGame(gamePlay gp){
    char yesOrNo;
    gp.place = "clearing";
    cout<<"You wake up slowly and only notice that your head is pounding. You finally notice that you feel dirt and dead leaves against your hands and your entire body aches from lying on something hard all night long. You open your eyes to see great big trees surrounding you and, when you look down, you see that you are lying on a bed of dead leaves. You try to remember what you did to get in the middle of the forest. The more you try to remember, the more you realize that you don’t remember anything, not even your own name. You shut your eyes close and scrunch up your face trying to remember your name."<<endl<<endl;
    cout<<"Please enter your name here: ";
    cin>>gp.player;
    cout<<endl;
    cout<<"Your eyes fly open with recognition. "<<gp.player<<"! That's your name! You're happy that you remember your name but you still have no idea how you ended up in a forest.You get up from the bed of dead leaves and decide to kick the leaves around, trying to see if you had anything with you. Just when you're about to stop kicking the leaves, your foot hits something hard. You carefully move the leaves aside to reveal a coin. It’s small and golden; it fits nicely in the palm of your hand. You wonder how you were even able to find it because of how small it is."<<endl<<endl;
    cout<<"Would you like to pick it up? ";
    cin>>yesOrNo;
    cout<<endl;
    if(yesOrNo == 'y'){
        gp.coin = true;
        cout<<"You decide that it might be useful, and the coin doesn’t take up that much space. You tuck it into your small pocket. Not much else besides the coin can fit in your pocket."<<endl<<endl;
    }
    else{
        cout<<"You decide that a coin doesn’t have much use in a deserted forest so you drop the coin back into the pile of leaves. You watch as it bounces off the leaves and rolls under them, hidden from the world again."<<endl<<endl;
    }
    cout<<"You quickly look over the rest of the dead leaves and the dark trees. Hanging from a low branch, you see a dark colored backpack. Not knowing what you might need to pick up to get out of the woods, you pick up the backpack and sling it across your back. Once the backpack is secure against your back, you look at the thick forest to try finding a way out. You see that the thick wall of trees thin out in three different directions. One on the left, one in the front, and one on the right."<<endl<<endl;
    directionOrItem(gp);
}

//changes place and tracks where the player is
void placeChange(gamePlay gp){
    if(gp.place == "clearing"){
        if(gp.direction == 'l'){
            gp.place = "cabin";
            cabin(gp);
        }
        else if(gp.direction == 'f'){
            gp.place = "berryWoods";
            berryOrWoods(gp);
        }
        else if(gp.direction == 'r'){
            gp.place = "mountain";
            mountain(gp);
        }
        else
            wrongDir(gp);
    }
    if(gp.place == "berryWoods"){
        if(gp.direction == 'r'){
            gp.place = "berryClearing";
            berryClearing(gp);
        }
        else if(gp.direction == 'f'){
            gp.place = "woods";
            woods(gp);
        }
        else if(gp.direction == 'b'){
            gp.place = "clearing";
            clearing(gp);
        }
        else
            wrongDir(gp);
    }
    if(gp.place == "cabin"){
        if(gp.direction == 'l')
            bedroom(gp);
        else if(gp.direction == 'b'){
            gp.place = "clearing";
            clearing(gp);
        }
        else
            wrongDir(gp);
    }
    if(gp.place == "berryClearing"){
        if(gp.direction == 'b'){
            gp.place = "berryWoods";
            berryOrWoods(gp);
        }
        else
            wrongDir(gp);
    }
    if(gp.place == "woods"){
        if(gp.direction == 'b'){
            gp.place = "berryWoods";
            berryOrWoods(gp);
        }
        else
            wrongDir(gp);
    }
    if(gp.place == "mountain"){
        if(gp.direction == 'l'){
            gp.place = "waterfall";
            waterfall(gp);
        }
        else if(gp.direction == 'b'){
            gp.place = "clearing";
            clearing(gp);
        }
        else
            wrongDir(gp);
    }
    if(gp.place == "waterfall"){
        if(gp.direction == 'b'){
            gp.place = "mountain";
            mountain(gp);
        }
        else
            wrongDir(gp);
    }
}

//prints out when player is in the cabin
void cabin(gamePlay gp){
    char yesOrNo;
    char holder;
    if(gp.cabin == false){
        gp.cabin = true;
        cout<<"You turn to the left and see that there is actually a small trail. There are two small dirt lines in the trail, maybe about 4 feet apart. It reminds you of wagon wheels. You get excited at the idea of another human around, or at least a horse that you could ride. You quickly jog down the trail. The farther down the trail you go, the more the trees disappear. All of a sudden the trees fan out to make a wide circle."<<endl;
        cout<<"Inside the circle is a small cabin and a fenced in field. The bottom half of the cabin is made from oddly pieced together rocks. It looks like whoever built the cabin spent more of their time trying to find rocks that would balance on top of each other instead of falling over. The top half of the cabin, including the roof, is made of thick logs that look like they were balanced better than the rocks. Leaning against the back of the cabin is a little wooden stall with a small hangover. The stall is clearly for a horse, but no horse is inside the stall. The field looks dry and there are thin cracks in the ground. There are small tufts of grass and weeds that tried to grow up from the crack in the field."<<endl;
        cout<<"You see no one outside, but you don’t get the feeling that the cabin is abandoned, so you walk up to the tired wooden door of the cabin and knock. The door cracks just the tiniest bit, like someone had thought they closed it, but hadn’t pulled it all the way with them. You don’t hear anything from inside, so you knock again and call out a greeting. This time you hear tiny feet scampering across the rocky floor of the cabin. The scraping goes all over the house, but one set of scraping runs straight to the door you’re standing at."<<endl<<endl;
        cout<<"Enter \'c\' to continue: ";
        cin>>holder;
        cout<<endl;
        cout<<"Two tiny little paws shove their way into the crack of the door and pull the door open. You see an animal with a tiny black mask permanently fixed around its eyes. The gray and black little thief finally sees you and scrapes its way across the floor to a different exit in the wall."<<endl;
        cout<<"With the door opened a little bit more, you see that the cabin has dirt all over the floors, no doubt from the creatures that stay there during the cold nights, and the chairs have been knocked down."<<endl;
        cout<<"You call out one last greeting while you pick up the chairs and put them around the table. You finally decide that the cabin is abandoned, but might not have been abandoned for long."<<endl;
        cout<<"You look around the cabin to see that it only has the essentials. The cabin is split in two: the room that you are in now and a wall on the left that separates what you assume is the bedroom. In the middle of the room is a wooden table with four wooden chairs surrounding it. Along the back wall is a door that leads to the back of the house and the makeshift horsestall. To the left of the door is a food prep area. The prep area runs along the back wall for two to three feet and then runs along the wall that separates the bedroom from the living room. There are no cabinets on the walls, but the prep area seems to have doors on the side of it. On the other side of the door is a rocked-in area in the corner that has a big hook in the wall, about waist height, and black dust all over the rocked floor. Only a small rock ledge keeps the black dust from spilling all over the rest of the cabin floor. You notice that everything looks handmade. You start to spin around, taking in all the work that someone did, when you notice an axe and a pickaxe leaning up against the wall next to the door."<<endl<<endl;
        cout<<"Do you want to pick up the axe and pickaxe? ";
        cin>>yesOrNo;
        cout<<endl;
        if (yesOrNo == 'y'){
            cout<<"You decide that an axe and a pickaxe might be something useful to have. You don’t know if they are sharp enough to cut your backpack or not, but you decide not to risk it. You wrap the top of the axe and pickaxe before slipping them into your backpack with part of the handles sticking out the top of the bag."<<endl;
            gp.axeAndPickAxe = true;
        }
        else{
            cout<<"You decide that you have no current use for the axe and pickaxe, so you leave them there. Hopefully the little thieves don’t drag them away before you need them."<<endl;
        }
    }
    else{
        cout<<"You walk through the clearing, taking in the smells of the clear air and dry earth. You walk up to the door, pounding your feet against the ground to make your entrance known and swing the door open. You quickly sweep your eyes around the room and are happy to see nothing moving in the cabin."<<endl<<endl;
        if(gp.axeAndPickAxe == false){
            cout<<"Do you want to pick up the axe and pickaxe? ";
            cin>>yesOrNo;
            cout<<endl;
            if (yesOrNo == 'y'){
                cout<<"You decide that an axe and a pickaxe might be something useful to have. You don’t know if they are sharp enough to cut your backpack or not, but you decide not to risk it. You wrap the top of the axe and pickaxe before slipping them into your backpack with part of the handles sticking out the top of the bag."<<endl;
                gp.axeAndPickAxe = true;
            }
            else{
                cout<<"You decide that you have no current use for the axe and pickaxe, so you leave them there. Hopefully the little thieves don’t drag them away before you need them."<<endl;
            }
        }
    }
    directionOrItem(gp);
}

//prints out if player goes into the bedroom
void bedroom(gamePlay gp){
    char yesOrNo;
    if(gp.bedroom == false){
        gp.bedroom = true;
        cout<<"You crack open the door to the bedroom, afraid that you might see a person or another little thief. When you see nothing, you open the door all the way and see that the bedroom is just like the living room - only the essentials. There is a large bed in the middle of the room, the headboard pushed against the wall. On the bed are two thin pillows and a thick woven blanket. Above the bed is a small glass window. It doesn’t look like the window can open, but it gives natural light to the room. On either side of the bed is a small side table with one drawer each. The bed looks inviting and you debate on whether you should lie down or not."<<endl<<endl;
        cout<<"Do you want to take a nap? ";
        cin>>yesOrNo;
        if(yesOrNo == 'y'){
            cout<<"You decide that a short nap won’t hurt. You drop your bag down at the foot of the bed and kick your shoes off before climbing under the thick blanket. You didn’t realize how tired you were until your head hits the pillow. As you start to drift off the sleep you hear a faint beeping sound. The beeps are steady and there is a space in between each beep. You crack one eye open and lazily sweep it across the room. You see nothing that would make that sound, so you close your eyes. Again, you hear the steady beeps. This time you think that it’s just some fly making an odd buzzing sound and don’t even check the room. The more you drift off, the more space there is in between the beeps, but you pay no attention to it. Right before you fully fall asleep, with a half working mind, you hear the beeps go from short beeps into one long sound. You give no attention to it and drift off into a dreamless sleep."<<endl;
            gameEndings();
        }
        else{
            cout<<"You decide that a nap would not be helpful to get out of this forest. You give the bed one long look before exiting the room and closing the door behind you."<<endl<<endl;
            direction(gp);
        }
    }
}

//has player enter the direction they want to go
void direction(gamePlay gp){
    cout<<"Enter what direction you want to go: ";
    cin>> gp.direction;
    cout<<endl;
    placeChange(gp);
}

//prints out what items the player has,
//has player enter what item they want to use,
//and checks if the item is being used in the proper place
void useItem(gamePlay gp){
    string item;
    cout<<"You have the current items:"<<endl;
    if(gp.coin)
        cout<<"coin"<<endl;
    if(gp.axeAndPickAxe)
        cout<<"axe"<<endl<<"pickaxe"<<endl;
    if(gp.sticks)
        cout<<"sticks"<<endl;
    if(gp.rocks)
        cout<<"rocks"<<endl;
    if(gp.fish)
        cout<<"fish"<<endl;
    if(gp.berries)
        cout<<"berries"<<endl;
    cout<<endl;
    cout<<"Enter what item you would like to use: ";
    cin>>item;
    cout<<endl;
    if(gp.place == "berryClearing"){
        if(item == "fish" && gp.fish == true){
            cout<<"You slowly slide your bag to the ground and dig out the fish that you have in your bag. The minute the raw fish comes out of your bag, the smell of it fills the air. The bear sniffs the air and starts to come towards you. Before the bear can take two steps towards you, you toss the fish into the woods and the bear chases after it. You stay frozen for another minute, hiding in the tall grass. When your heartbeat is stable, you get up to pick a few berries. You take a new leaf from the growth around you to wrap the berries in. You get into a routine when picking the berries. One for later, two for now. Only when the leaf and your stomach are full of berries, do you stop picking them. You fold the leaf up to make a packet of berries, which you slip into an outside pocket on your bag."<<endl<<endl;
            gp.fish = false;
            gp.berries = true;
            allTasksDone();
        }
        else{
            cout<<"That doesn’t work."<<endl<<endl;
            directionOrItem(gp);
        }
    }
    else if(gp.place == "woods"){
        if(item == "axe" && gp.axeAndPickAxe == true){
            cout<<"You think that this place is a wood yard and that people used to come here for their wood. You think that cutting down some of the thinner trees or tree limbs might be useful. You take your axe out and lean your bag up against a tree. You start with the smaller trees, cutting those down and then taking off any branches that you don’t want, leaving a nice clean stick. You do the same thing with some branches off the thicker trees. Once you have gathered a small armful of sticks, you wrap the axe back up and put it away in your bag. You then take the sticks that you gathered and grab a thin vine off a tree. You tie the vine around the sticks to keep them together and tuck them into your backpack, careful not to put anything heavy on top of them."<<endl<<endl;
            gp.sticks = true;
            directionOrItem(gp);
        }
        else{
            cout<<"Why did you think that would work?"<<endl<<endl;
            directionOrItem(gp);
        }
    }
    else if(gp.place == "mountain"){
        if(item == "pickaxe" && gp.axeAndPickAxe == true){
            cout<<"You look at the mountain and realize that you could possibly use some rocks. You take the pickaxe out of your bag and set your bag off to the side, out of the way. You swing the pickaxe against the wall of rock and slowly small chunks of rock fall out of the mountain. Once you have chunks of rocks littered around your feet, you stop swinging. Your arms and shoulders are sore, but you feel like you have enough rocks for now. You wrap up the pickaxe again and slip it into your bag next to the axe. You then carefully stack the rocks up in your bag, making sure to not break anything else in your bag. Once everything is situated, you zip up the backpack and carefully put it back on."<<endl<<endl;
            gp.rocks = true;
            directionOrItem(gp);
        }
        else{
            cout<<"That doesn’t work."<<endl<<endl;
            directionOrItem(gp);
        }
    }
    else if(gp.place == "waterfall"){
        if(item == "rocks" || item == "sticks"){
            if(gp.rocks == true && gp.sticks == true){
                cout<<"You look at the fish in the pond and wonder to yourself if you can catch one of them. You take the rocks and sticks out of your bag and set them on the ground next to the pond. You first take the sticks and walk into the pond, just deep enough to where the fish were willing to go. You start to jam the sticks into the soft sand and dirt that covers the bottom of the pond. You make three sides of a square with the sticks. With the remaining sticks you make the last side of the square, but the middle of that side curved into the middle of the square to make a v-shape. When you’re satisfied with the misshaped square you go back to the edge of the pond where you set the rocks down. You take a few rocks at a time and go back to square of sticks. You had jammed the sticks pretty far into the ground, but to make sure that they are not going to move, you set rocks along the inside and outside of the sticks. Once All of your sticks and rocks are gone, and the trap is finished, you sit down to look at your handywork. You feel proud looking at the makeshift trap, but you also feel hot, sweaty, and dirty. You decide that while you wait to see if your trap works you would soak in the pond water. You swim along the edge of the pond to the waterfall and use the edge of the waterfall to wash off all the dirt that you had accumulated. You then swim back to the edge of the pand and lay down. With your back still getting wet and your legs lazily floating on the top of the water, you drift off into old memories and think about what you will do when you get home. You think that you have given the fish enough time to get trapped if they are going to get stuck in your trap. You sit up and see a fish splashing at the top of your trap. It worked! You have no idea how it worked, but you don’t question it too much as you collect your prize. The fish wiggles around in your hand as you carry it towards the edge of the pond. You set it down next to your bag and then walk to the edge of the forest where big green leaves are growing. You grab a few leaves and walk back to the fish, who has now stopped moving. You wrap the fish up, making sure to give it multiple leaf layers, and slip it into a small pocket on your bag. You leave your fish trap alone for the next time you want a fish."<<endl<<endl;
                gp.rocks = false;
                gp.sticks = false;
                gp.fish = true;
                directionOrItem(gp);
            }
            else{
                cout<<"You feel like you are missing something for that to work."<<endl<<endl;
                directionOrItem(gp);
            }
        }
        else if(item == "coin" && gp.coin == true){
            cout<<"You dig out the little coin that you had slipped into your pocket. You take a minute to look at the coin. When you are ready, you give the coin your greatest wish, the wish to go home. You watch as the coin flies in the air and catches a few rays of sunshine before making ripples in the water. You watch the coin sink all the way to the bottom of the pond where the fish are already starting to inspect the shiny object. As you watch the fish crowd around the coin, you notice that the fish start to merge and blur together. The pond starts to get brighter and brighter until it turns white. The mountain, ground, trees, and waterfall all seem to be sucked into the white pond. Left over is white; everything is white. You turn around trying to find a way out, a way back to the forest, but there is none. The white gets too bright for you, so you close your eyes. When you open them again, you see a bright light above you and white walls around you. You notice that you're lying down instead of standing up. As you gain more consciousness, you hear a steady beeping sound and a few voices. Your eyes slowly drag across the room and you see two people. One is standing with a white, knee-length jacket and the other is in a plain t-shirt and jeans. The one in jeans looks worn out, like they have spent the last few days not sleeping and worrying about something, or someone. When both people realize that you're awake, the one wearing jeans smiles brightly and walks to the side of your bed."<<endl;
            cout<<"\""<<gp.player<<" you’re awake. I’ve missed you so much.\""<<endl;
            cout<<"That’s when you remember who this person is, your other half. You smile up at them and grip their hand hoping that you never leave them again."<<endl<<endl;
            gameEndings();
        }
        else{
            cout<<"Why did you think that would work?"<<endl<<endl;
            directionOrItem(gp);
        }
    }
    else {
        cout<<"Why did you think that would work?"<<endl<<endl;
        directionOrItem(gp);
    }
}

//has the player enter if they want to change direction or if they want to use item
void directionOrItem(gamePlay gp){
    char dirOrItem;
    bool x = true;
    while(x){
        cout<<"Enter direction (d) or item (i): ";
        cin>>dirOrItem;
        cout<<endl;
        if(dirOrItem == 'd')
            direction(gp);
        else if(dirOrItem == 'i')
            useItem(gp);
        else{
            cout<<"That doesn't work."<<endl;
            continue;
        }
    }
}

//ends the game
void gameEndings(){
    cout<<"Thank you for playing!"<<endl;
    exit(0);
}

//if the player enters a wrong direction or something that isn't a direction
void wrongDir(gamePlay gp){
    cout<<"Better not try that, you don’t want to get lost."<<endl;
    cout<<"Enter a different direction: ";
    cin>>gp.direction;
    cout<<endl;
    placeChange(gp);
}

//prints when the player is in the clearing
void clearing(gamePlay gp){
    cout<<"You look down at the bed of leaves that you woke up from. You hear the crunch of leaves and you walk to the middle of the clearing to see the different directions you could go. There is a path to the left, to the right, and forward."<<endl<<endl;
    directionOrItem(gp);
}

//prints when player is on the train to the berry clearing and woods
void berryOrWoods(gamePlay gp){
    if(gp.berryOrWoods == false){
        gp.berryOrWoods = true;
        cout<<"You look at the path ahead of you. The trees give a nice wide path, almost like they are trying to lead you in the right direction. You walk down the path and glance at the trees as you walk past them. The trees along the path are thick with dark bark. They reach up over your head to twine together. Little patches of light have to fight their way through the tree branches to light the path. You are so wrapped up in looking at the trees that you almost don’t notice a small trail on the right side of the path. You debate whether you want to continue on your current path or if you want to turn right down the small trail."<<endl<<endl;
        directionOrItem(gp);
    }
    else{
        cout<<"You walk down the wide path, still awestruck by the thick trees that form a wall on either side of the path. You see the small path on the right and the main path continue forward."<<endl<<endl;
        directionOrItem(gp);
    }
}

//prints when the player is in the berry clearing
void berryClearing(gamePlay gp){
    if(gp.berryClearing == false){
        gp.berryClearing = true;
        cout<<"You look down the small path. You think you see a small clearing with maybe some small bushes or small trees? Your curiosity gets the better of you and you go down the small trail to the clearing. You hear rustling as you get closer to the clearing. The first thing you notice is that there are berry bushes! Tall grass covers the floor of the clearing and shows where animals have trampled about getting their own berries. You hear your stomach grumble, as if to tell you how hungry it is. Sadly you are not the only one that heard your stomach growling. A bear who had been fulfilling its own hunger looks up at you, their black eyes putting you in a frozen state. You try to think of something that could distract the bear while you pick some berries."<<endl<<endl;
        directionOrItem(gp);
    }
    else{
        if(gp.bear == true){
            cout<<"You slowly creep into the berry clearing, making sure not to make too much noise. The bear is already watching you as you enter the clearing. It seems like it might be waiting for you to give it something."<<endl<<endl;
            directionOrItem(gp);
        }
        else{
            cout<<"You enter the clearing, careful in case the bear comes back. When you see no bear, you give a sigh of relief."<<endl<<endl;
            directionOrItem(gp);
        }
    }
}

//prints when the player is in the woods
void woods(gamePlay gp){
    if(gp.woods == false){
        gp.woods = true;
        cout<<"You decide to continue going forward. The trees seem to get thicker the farther you walk down the path, and they seem to slowly grow closer and closer together. Thick vines start to crawl their way across the ground and up the trees. It starts to get hard to see where the path is anymore and just when you are about to try finding your way back to the path, the trees thin out. There are a few thin trees that are sprinkled about the place in front of you and the floor of the forest is covered in wood chips."<<endl<<endl;
        directionOrItem(gp);
    }
    else{
        cout<<"You walk down the narrowing path to the tree graveyard. When you reach the end of the path, you see the layer of wood chips that cover everything and the few trees that seem to have survived the massacre."<<endl<<endl;
        directionOrItem(gp);
    }
}

//prints when the player is by the mountain
void mountain(gamePlay gp){
    if(gp.mountain == false){
        gp.mountain = true;
        cout<<"You follow a small deer path that weaves through small, thin trees. You wonder if maybe you should turn back and find your way back to the clearing. Just as you think this, you run face-first into a hard rock. You look up and see that the rock stretches up to the sky, like it is trying to touch the soft clouds that are slowly drifting through the bright blue sky. Along either side of the mountain there is a small trail that the trees couldn’t grow on and the animals used to easily get through the woods. To the left of you, the small trail seems more packed down from the animals than the right."<<endl<<endl;
        directionOrItem(gp);
    }
    else{
        cout<<"You follow the small trail, but right before you hit the rock wall, you stop. You see the animal trail continue to the left of the mountain and the small path through the trees behind you."<<endl<<endl;
        directionOrItem(gp);
    }
}

//prints when the player is by the waterfall
void waterfall(gamePlay gp){
    if(gp.waterfall == false){
        gp.waterfall = true;
        cout<<"You follow the trail further along the mountain. You keep your eyes on the ground for most of the time due to the ground being more uneven here than the other places in the woods. When you notice that the trees on your left seem to disappear and the mountain on your right seems to bend away from you, you look up. In front of you is a beautiful waterfall. The waterfall comes from someplace on the side of the mountain and falls down into a small pond. The water is crystal clear and it is as blue as the sky. You can see the fish swimming around at the bottom of the pond. The trees around the pond are a bright green color and seem to grow up and towards the pond, as if praising the pond and waterfall for the water it provides. The water reminds you of a little pond that you had back at home that your family had made into the \"wishing pond.\""<<endl<<endl;
        directionOrItem(gp);
    }
    else{
        cout<<"You follow the small animal trail down to the waterfall. The sun glistens off the surface of the water and a soft breeze pushes the plants around. The fish swim lazily around the pond, not worrying about anything."<<endl<<endl;
    
        directionOrItem(gp);
    }
}

//prints when the player has finished all the tasks of the game
void allTasksDone(){
    cout<<"You have worked all day and when you finally look up, you see that the sun is setting. You feel tired and can’t think of anything that you can do at night that would get you out of these woods, so you make your way to the cabin you found earlier. You pass thick trees following the last few rays of sunshine to the cabin. The cabin reflects the last bit of light from the sun, making it look like a little patch of heaven. You walk into the cabin and drop your bag onto the wooden table, making sure to make a loud enough sound to scare away any stowaways in the cabin. You walk to the empty bed in the next room and tuck yourself in. As you start to drift off the sleep, you hear a faint beeping sound. The beeps are stead and there is a space in between each beep. You crack one eye open and lazily sweep it across the room. You see nothing that would make that sound, so you close your eyes. Again, you hear the steady beeps. This time you think that it’s just some fly making an odd buzzing sound and don’t even check the room. The more you drift off, the more space there is in between the beeps, but you pay no attention to it. Right before you fully fall asleep, with a half working mind, you hear the beeps go from short beeps into one long sound. You give no attention to it and drift off into a dreamless sleep."<<endl<<endl;
    gameEndings();
}
