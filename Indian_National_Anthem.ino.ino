/*
Copyright(c)- Bhaskar Tripathi
Note - Being a part time flute player, I have tried to write the notes as close as possible but it is still not very refined. 
You may try to experiment more with the notes array to futher refine it.
*/
int speakerPin = 7; //buzzer is connected to Pin 11 of the Board.

int length = 149; // the number of notes 
char notes[] = "cdeeeeeeeeedef eeedddbdc ccgggggggggaf fffffeddf eedeedeggaff eeeeeddbdc cdeeeedf efgggfedfe feeeddbdc ccggggeggggga fffffedfe egc bab aga ccddeedef "; // a space represents a rest
//char notes[] = "ccddeeeeeeedef eeedddb-dc cggggggggf#ag fffeeedfe eeeeedgggff eeedddb-dc cdeeeedef efgggfedfe eedddb-dc ggggggggggf#ag fffeeedfe egc+ bab aga ccddeedef "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1,
                2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 2, 2, 2, 1, 1,
                1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                1, 1, 4, 1, 1, 1, 4, 1, 1, 1, 4, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 4, 1 };

int tempo = 200; //set tempo

void playTone(int tone, int duration) {  //created a square wave for given time duration
  for (long i = 0; i < duration * 1000L; i += tone * 2) { 
    digitalWrite(speakerPin, HIGH); 
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW); 
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) { //Assigning high time for the notes
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 956, 851, 758, 716, 638, 568, 1014, 478 }; 

  // play the tone corresponding to the note name 
  for (int i = 0; i < 8; i++) { 
    if (names[i] == note) { 
      playTone(tones[i], duration); 
    }
  }
}

void setup() { 
  pinMode(speakerPin, OUTPUT); // pin 7 as an OutPut Pin
}

void loop() {  //Main function
  for (int i = 0; i < length; i++) {  //For the length of the tune array
    if (notes[i] == ' ') {  //take space as rest
      delay(beats[i] * tempo); // rest 
    } else { 
      playNote(notes[i], beats[i] * tempo); //play the corresponding note for the corresponding beat
    } 

    // pause between notes 
    delay(tempo / 2); 
  } 
}
