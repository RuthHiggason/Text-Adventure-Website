"""
Mansion Mystery - Part 1: House Layout
----------------------------------------
This is the skeleton of the text adventure. It only handles moving
between rooms based on the hand-drawn map. Room descriptions below
are TEMPORARY placeholder text - swap them out once the story,
clues, and characters are written.

Layout implemented from the sketch:

Downstairs:
    Dining Room -- Living Room -- (Office / Library)
         |               |
      Kitchen          Garden
         |               |
       Garden  <---------'
    (Garden has two separate doors in: one from the Kitchen, one
     from the Living Room)

Upstairs (reached by stairs from the Living Room):
    West Hallway: Lost Child's Room, Lover's Room, Sibling's Room
    East Hallway: Guest Room, Master's Room, Butler's Room
    West Hallway <---> East Hallway
"""

CAR_SCENE = """\
You wake up with a low throb in your head as it bangs against what feels
like a car door. After multiple hours on the road, none of which you're
driving, you get used to the feeling of a good car door as a pillow. You
crack your eyes open, immediately shutting them from the sharp pain that
the sun brings you. You carefully crack one eye open, anticipating the
pain but ready to bear it to find where you are. Through your slitted
eyes, you can see that you are in the back seat of a car. You open your
eyes fully and lock eyes with the driver through the rearview mirror.

"Ah, you're awake. Perfect timing," the driver says.

You furrow your eyebrows. "Perfect timing for what?" you ask.

"Umm, your ride is over. Do you not recognize this house?" the driver
sounds concerned. You can't tell if it's concern for you or concern that
he might have gone to the wrong house.

You look out the window and see a large, two-story house with steep
peaks on the roof. The house looks old, like it came straight out of the
black-and-white version of The Addams Family. The only difference from
the house in The Addams Family is that this one looks like it was owned
by someone who enjoyed more colors.

The house is a light tan color with white pillars supporting the black
roof. The windows that line the second story seem to be spaced out
evenly, like someone with OCD took a ruler to them. The same can be said
for the first story, but the line of windows is broken by thick, black
double doors. To the left of the door, there's a flourishing garden. The
garden is filled with colorful flowers, fruits, and vegetables of all
kinds. There's a thin path that snakes around the garden in a vague oval
shape, with a pinch in the oval leading to a small door between two
windows, careful not to push the windows from the OCD placement of them.

You feel the car slide to the left as it gently turns around the
circular driveway, stopping so that your car door is right in front of
the black double doors. The driver puts the car in park and swings
around to look at you with an expectant look.

"Oh, yes. This is the house," you respond, not fully convinced that this
is the right house, but something about it feels familiar.

The driver nods in approval and flips back around, grabbing the wheel.
Clearly, they want you out of the car so they can get to their next job.
You push the car door open and get out. The second you close the door,
the car peels off. Your eyes track the car until it disappears down the
driveway, trees covering the car from view. You slowly turn around,
making note that the house is surrounded by trees and the driveway is
long enough that you can't see the road, but something deep in you can
tell that the road is a long way from the house.

When your eyes lock onto the black doors, you suck in a breath."""

WALK_TO_DOOR_YES = (
    "You slowly walk to the doors and lift your hand to knock, but "
    "something stops you."
)

WALK_TO_DOOR_NO_FIRST = """\
You stand there staring at the black doors, waiting for something. You
make up your mind: you're leaving this place even if you have to walk a
thousand miles. You go to take a step back, but instead your leg goes
forward towards the front door. You look at your leg with a puzzled
look. You go to take another step backwards, and again, your leg goes
forward. You look back at the black door, knowing that you will be at
that door in a matter of minutes with or without your approval."""

WALK_TO_DOOR_NO_SECOND = """\
You struggle with your own body. You try to slide your feet back, but
only manage to slide them forward. You lose your footing and land on the
gravel driveway. You try to scoot back, but just end up with a lot of
gravel dust on your clothes and, of course, closer to the black door. At
this point you are only about a foot away, and the door looms above you,
daring you to try running away. Knowing you can't fight your own body
forever, you give in.

"I'm getting up now, you'll let me do that at least, right?" You call
out to yourself, pausing for an invisible response you know you'll
never get.

You sigh and push against the ground. You're pleased that you seem to be
in control again as you stand up and brush the dust off. You take a step
forward, making the door right in front of you within reach."""

LIVING_ROOM_DESCRIPTION = """\
As if on its own, your hand lowers to grab the handle, pushing the latch
down and pushing the door in.

"Hello?" you call out. You're not really expecting a response, but you
still feel the need to call out. As expected, no response is given back.

You walk through the door and gently close the door behind you with a
thud. You look around, taking in the large living room.

The walls are a forest green color, and the floor is a dark brown wooden
floor. Around the front door is a small square of black rock tile that
you are currently standing on. To your right are two regal couches that
face each other with a low dark brown table in between them. Spread
under the couches and table is a square rug that matches the color of
the walls. In the middle of the wall on the right is a small hallway.
You can't see where it leads to, but you can see the edge of a door, the
same dark brown as the floors and table. To the right of you are two
chairs, the kind of chairs that you know you could spend hours reading
or chatting with your best friend in. The chairs are pushed against the
wall, slightly angled towards each other with a small round table placed
in the middle for drinks. Slightly in front of the chairs is a small
square table with swirls and flowers carved into the legs and edges of
the table. On top of the table is a chessboard, set up ready for a game
of wits for whoever sits down. The chairs placed on either side of the
table have tall backs and armrests, also carved with the same swirls and
flowers that the table has. Stretching under all the chairs and tables
is a matching green rug, as on the right side. Directly to your right,
in front of the chairs, is a large archway, and through the archway you
can see a long dark wooden table with at least 10 chairs surrounding it.
Between the two rugs is about 6 feet of space, making it feel like a
runway that leads straight to the grand staircase. The staircase matches
the rest of the room, being made of the same dark brown colored wood and
a runner the same forest green as everything else. Clearly, whoever
lived here was very intentional with the design, and it makes you
believe that the rest of the house is the same dark wood and forest
green color.

You are about to take a step forward, ready to find the owner, but a
knock on the door booms around the living room."""

ANSWER_DOOR_YES = """\
You spin around and rip the door open, hoping to get some answers as to
where you are and who owns this house.

In front of you is a young man in a uniform. You can't see what the
uniform says because he's carrying a small stack of tin food containers.

"Where do you want all this?" the man asks, lifting the containers a
little and jerking his head behind him to show three more people
carrying the same tin food containers.

"Umm, I'm not the owner of this house," you respond, hoping that the man
might have a number or something to the real owner.

"I don't care if you're the Queen of England or the guy that picks up
her toenail clippings. This is the address I have, and I need to drop
this food off before we leave, so we can leave it on the doorstep or the
kitchen table. Your choice," the guy snips back with an expectant look,
waiting for your response.

You take a sharp breath in while you think. You don't want the owner to
be upset that their food is left outside, but you don't know if you
should let them in.

"Ok," you breathe out, stepping aside to let them in. You decide to
trust that he's in too much of a rush to stop and kill you or steal
something, so it's probably safe to let him in.

He rushes in with his posse of food delivery people and takes a sharp
left to the dining room. You follow close behind him.

"Do you know where the owner is? Or how to contact them?" you ask the
delivery guy.

"Don't know, don't care," he responds, dropping the food on the table
and gesturing for the other people to do the same.

"You can't tell me anything?" you desperately plead for any morsel of
information you can get.

The guy and his posse have dropped the food off and are speeding towards
the door like their pants are on fire, and the only water is through
that black front door.

"No, I got nothin' to give you. If you can't find them, I guess you have
a lot of free food," he yells over his shoulder and slams the door shut
in your face, leaving the thud of the door and you alone in the living
room. You glance back at the food on the table, wondering how long you
wait until you deem the food fair game to take."""

ANSWER_DOOR_NO = """\
You freeze, waiting for the knocking to stop. You very slowly put your
ear up to the door, careful not to put any weight on the door so that it
doesn't creak. You can hear someone outside, but you can't hear what
they are saying. You jump back as another round of knocking happens
again.

"Helloooo?" You hear from outside. The speaker sounds annoyed, and you
still don't respond.

You slowly put your ear against the door again. You hear muffled voices
and shuffling around. There's more than one person, but you can't tell
why they're there. The only clear sound you can hear is the slamming of
doors and a car driving off. You creep to the window right next to the
door and peek out. If someone was looking at you, they would only see
your eyes and forehead. Thankfully for you, no one seems to be out
there, but there is a stack of tin containers stacked next to the door.

After looking around a bit more, you determine that no one is out there,
and your curiosity is fixated on the tin containers. You open the door
and pick up the tin on top. It's a food container, and the smell coming
from it is making your mouth water. You look at the stack and note that
the entire stack is food containers.

Deciding that you really don't want food to sit outside, even if it
isn't your own food, you grab a few containers and carry them to the
dining table left of the living room. It takes you two more trips to
carry all the boxes from the front door to the table, but when you get
them all in, you go back and close the door. You lean on the door and
stare at the food to the left of you, debating what to do next."""

INTRO_CLOSER = (
    "As much as it pains you to walk away from such good smelling food, "
    "you decide that you should try looking for the owner of the house "
    "before you dig in."
)


def ask_yes_no(prompt):
    """Ask a yes/no question and keep asking until we get a clear answer."""
    while True:
        answer = input(f"\n{prompt} (yes/no) > ").strip().lower()
        if answer in ("yes", "y"):
            return True
        if answer in ("no", "n"):
            return False
        print("Please answer 'yes' or 'no'.")


def play_intro():
    """Run the opening car-to-living-room scene before the map opens up."""
    print(CAR_SCENE)

    if ask_yes_no("Do you walk to the door?"):
        print()
        print(WALK_TO_DOOR_YES)
    else:
        print()
        print(WALK_TO_DOOR_NO_FIRST)
        if ask_yes_no("Do you walk to the door?"):
            print()
            print(WALK_TO_DOOR_YES)
        else:
            print()
            print(WALK_TO_DOOR_NO_SECOND)

    print()
    print(LIVING_ROOM_DESCRIPTION)

    if ask_yes_no("Do you answer the door?"):
        print()
        print(ANSWER_DOOR_YES)
    else:
        print()
        print(ANSWER_DOOR_NO)

    print()
    print(INTRO_CLOSER)


ROOMS = {
    "living_room": {
        "name": "Living Room",
        "first_visit": LIVING_ROOM_DESCRIPTION,
        "repeat_visit": (
            "You're back in the living room. The forest green walls and dark "
            "wood furniture look just as intentional as the first time you "
            "saw them. The tin food containers are still sitting on the "
            "dining table through the archway."
        ),
        "exits": {
            "dining room": "dining_room",
            "garden": "garden",
            "office": "office",
            "library": "library",
            "upstairs": "west_hallway",
        },
    },
    "dining_room": {
        "name": "Dining Room",
        "first_visit": (
            "[PLACEHOLDER] The Dining Room, first visit text. Long table, "
            "place settings, etc."
        ),
        "repeat_visit": "[PLACEHOLDER] The Dining Room again, repeat visit text.",
        "exits": {
            "living room": "living_room",
            "kitchen": "kitchen",
        },
    },
    "kitchen": {
        "name": "Kitchen",
        "first_visit": "[PLACEHOLDER] The Kitchen, first visit text.",
        "repeat_visit": "[PLACEHOLDER] The Kitchen again, repeat visit text.",
        "exits": {
            "dining room": "dining_room",
            "garden": "garden",
        },
    },
    "garden": {
        "name": "Garden",
        "first_visit": (
            "[PLACEHOLDER] The Garden, first visit text. There are two doors "
            "back inside: one to the Kitchen, one to the Living Room."
        ),
        "repeat_visit": "[PLACEHOLDER] The Garden again, repeat visit text.",
        "exits": {
            "kitchen": "kitchen",
            "living room": "living_room",
        },
    },
    "office": {
        "name": "Office",
        "first_visit": "[PLACEHOLDER] The Office, first visit text.",
        "repeat_visit": "[PLACEHOLDER] The Office again, repeat visit text.",
        "exits": {
            "living room": "living_room",
            "library": "library",
        },
    },
    "library": {
        "name": "Library",
        "first_visit": "[PLACEHOLDER] The Library, first visit text.",
        "repeat_visit": "[PLACEHOLDER] The Library again, repeat visit text.",
        "exits": {
            "living room": "living_room",
            "office": "office",
        },
    },
    "west_hallway": {
        "name": "West Hallway (Upstairs)",
        "first_visit": (
            "[PLACEHOLDER] You reach the west end of the upstairs hallway. "
            "Doors lead to the Lost Child's Room, the Lover's Room, and the "
            "Sibling's Room. The hallway continues east."
        ),
        "repeat_visit": "[PLACEHOLDER] The west hallway again, repeat visit text.",
        "exits": {
            "downstairs": "living_room",
            "lost child's room": "lost_child_room",
            "lover's room": "lovers_room",
            "sibling's room": "siblings_room",
            "east hallway": "east_hallway",
        },
    },
    "east_hallway": {
        "name": "East Hallway (Upstairs)",
        "first_visit": (
            "[PLACEHOLDER] You reach the east end of the upstairs hallway. "
            "Doors lead to the Guest Room, the Master's Room, and the "
            "Butler's Room. The hallway continues west."
        ),
        "repeat_visit": "[PLACEHOLDER] The east hallway again, repeat visit text.",
        "exits": {
            "west hallway": "west_hallway",
            "guest room": "guest_room",
            "master's room": "masters_room",
            "butler's room": "butlers_room",
        },
    },
    "lost_child_room": {
        "name": "Lost Child's Room",
        "first_visit": "[PLACEHOLDER] The Lost Child's Room, first visit text.",
        "repeat_visit": "[PLACEHOLDER] The Lost Child's Room again, repeat visit text.",
        "exits": {"hallway": "west_hallway"},
    },
    "lovers_room": {
        "name": "Lover's Room",
        "first_visit": "[PLACEHOLDER] The Lover's Room, first visit text.",
        "repeat_visit": "[PLACEHOLDER] The Lover's Room again, repeat visit text.",
        "exits": {"hallway": "west_hallway"},
    },
    "siblings_room": {
        "name": "Sibling's Room",
        "first_visit": "[PLACEHOLDER] The Sibling's Room, first visit text.",
        "repeat_visit": "[PLACEHOLDER] The Sibling's Room again, repeat visit text.",
        "exits": {"hallway": "west_hallway"},
    },
    "guest_room": {
        "name": "Guest Room",
        "first_visit": "[PLACEHOLDER] The Guest Room, first visit text.",
        "repeat_visit": "[PLACEHOLDER] The Guest Room again, repeat visit text.",
        "exits": {"hallway": "east_hallway"},
    },
    "masters_room": {
        "name": "Master's Room",
        "first_visit": "[PLACEHOLDER] The Master's Room, first visit text.",
        "repeat_visit": "[PLACEHOLDER] The Master's Room again, repeat visit text.",
        "exits": {"hallway": "east_hallway"},
    },
    "butlers_room": {
        "name": "Butler's Room",
        "first_visit": "[PLACEHOLDER] The Butler's Room, first visit text.",
        "repeat_visit": "[PLACEHOLDER] The Butler's Room again, repeat visit text.",
        "exits": {"hallway": "east_hallway"},
    },
}

START_ROOM = "living_room"


def describe_room(room_key, visited):
    """Print the room's first-visit or repeat-visit text, then its exits."""
    room = ROOMS[room_key]
    print()
    print(f"== {room['name']} ==")
    if room_key in visited:
        print(room["repeat_visit"])
    else:
        print(room["first_visit"])
        visited.add(room_key)

    exit_names = ", ".join(sorted(room["exits"].keys()))
    print(f"\nExits: {exit_names}")


def main():
    current_room = START_ROOM
    visited = set()

    print("=" * 50)
    print("THE MANSION")
    print("=" * 50)

    play_intro()

    # The intro already fully described the living room, so mark it
    # visited (no need to print it again) and just show the exits.
    visited.add(current_room)
    room = ROOMS[current_room]
    exit_names = ", ".join(sorted(room["exits"].keys()))
    print(f"\nExits: {exit_names}")
    print("\n(From here on, type 'go <place>' to move, 'look' to re-read")
    print("the room, or 'quit' to exit.)")

    while True:
        command = input("\n> ").strip().lower()

        if command in ("quit", "exit", "q"):
            print("Goodbye.")
            break

        if command in ("look", "l"):
            # Re-show the room without re-triggering "first visit" text.
            room = ROOMS[current_room]
            print(f"\n== {room['name']} ==")
            print(room["repeat_visit"])
            exit_names = ", ".join(sorted(room["exits"].keys()))
            print(f"\nExits: {exit_names}")
            continue

        if command.startswith("go "):
            destination = command[3:].strip()
        else:
            destination = command

        exits = ROOMS[current_room]["exits"]
        if destination in exits:
            current_room = exits[destination]
            describe_room(current_room, visited)
        else:
            print("You can't go that way. Try one of the listed exits.")


if __name__ == "__main__":
    main()
