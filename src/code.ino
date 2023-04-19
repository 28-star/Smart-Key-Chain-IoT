#include "UbidotsESPMQTT.h"
#include <pitches.h>

int buz_pin = D8;
int curr_time = millis();

/**************
 * Define Constants
 **************/
char*  TOKEN= "YOUR-TOKEN" ;    // Your Ubidots TOKEN
char*  WIFINAME ="YOUR-WIFI-NAME";  // Your SSID
char*  WIFIPASS= "YOUR-WIFI-PASSWORD;";  // Your Wifi Pass
boolean buzzing = false;
char song_to_play = '0';
Ubidots client(TOKEN);

/**************
 * Auxiliar Functions
 **************/

void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");

    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    
    char* toggle_topic = "/v1.6/devices/nodemcu/toggle/lv";

    if(!strcmp(topic, toggle_topic)) {
        if((char)payload[0]=='1'){
            buzzing = true;
        }
        else { 
            buzzing = false;
            }
    }
    else {
        song_to_play = (char)payload[0]; 
        }
    Serial.println();
    
    if(buzzing) {
        switch(song_to_play) {
            case '1':mario_song(buz_pin);break;
            case '2':harry_potter_song(buz_pin);break;
            case '3':bella_ciao(buz_pin);break;
            case '4':christ_song(buz_pin);break;
            default:break;
        }
      
        if(song_to_play == '1' || song_to_play == '2' || song_to_play == '3' || song_to_play == '4') {
            buzzing=false; Serial.println("*********");
            client.add("toggle", 0);  // Insert your variable Labels and the value to be sent
            client.ubidotsPublish("nodemcu");}
        }
    else noTone(buz_pin);
}

/**************
 * Main Functions
 **************/
void setTone(int pin, int note, int duration) {
  tone(pin, note, duration);
  delay(duration);
  noTone(pin);
}

void harry_potter_song(int buzzer_pin) {
    struct MusicStruct {
        int A = 550;
        int As = 582;
        int B = 617;
        int C = 654;
        int Cs = 693;
        int D = 734;
        int Ds = 777;
        int E = 824;
        int F = 873;
        int Fs = 925;
        int G = 980;
        int Gs = 1003;
        int A2 = 1100;
        int A2s = 1165;
        int B2 = 1234;
        int C3 = 1308;
        int C3s = 1385;
        int D3 = 1555;
    } Music;

    struct LengthStruct {
        float half = 0.5;
        float one = 1.0;
        float one_half = 1.5;
        float two = 2.0;
        float two_half = 2.5;
    } Length;

    int tempo = 400;
    setTone(buzzer_pin, Music.B, tempo * Length.one);
    setTone(buzzer_pin, Music.E, tempo * Length.one_half);
    setTone(buzzer_pin, Music.G, tempo * Length.half);
    setTone(buzzer_pin, Music.F, tempo * Length.one);
    setTone(buzzer_pin, Music.E, tempo * Length.two);
    setTone(buzzer_pin, Music.B2, tempo * Length.one);
    setTone(buzzer_pin, Music.A2, tempo * Length.two_half);
    setTone(buzzer_pin, Music.Fs, tempo * Length.two_half);

    setTone(buzzer_pin, Music.E, tempo * Length.one_half);
    setTone(buzzer_pin, Music.G, tempo * Length.half);
    setTone(buzzer_pin, Music.F, tempo * Length.one);
    setTone(buzzer_pin, Music.Ds, tempo * Length.two);
    setTone(buzzer_pin, Music.F, tempo * Length.one);
    setTone(buzzer_pin, Music.B, tempo * Length.two_half);
    delay(50);  
}

void beep_sound(int buz_pin) {
    digitalWrite(buz_pin, HIGH);
    Serial.println("state: HIGH");
    delay(100);
    digitalWrite(buz_pin, LOW);
    delay(100);
}

void mario_song(int melodyPin) {
    int melody[] = {
        NOTE_E7, NOTE_E7, 0, NOTE_E7,
        0, NOTE_C7, NOTE_E7, 0,
        NOTE_G7, 0, 0,  0,
        NOTE_G6, 0, 0, 0,

        NOTE_C7, 0, 0, NOTE_G6,
        0, 0, NOTE_E6, 0,
        0, NOTE_A6, 0, NOTE_B6,
        0, NOTE_AS6, NOTE_A6, 0,

        NOTE_G6, NOTE_E7, NOTE_G7,
        NOTE_A7, 0, NOTE_F7, NOTE_G7,
        0, NOTE_E7, 0, NOTE_C7,
        NOTE_D7, NOTE_B6, 0, 0,

        NOTE_C7, 0, 0, NOTE_G6,
        0, 0, NOTE_E6, 0,
        0, NOTE_A6, 0, NOTE_B6,
        0, NOTE_AS6, NOTE_A6, 0,

        NOTE_G6, NOTE_E7, NOTE_G7,
        NOTE_A7, 0, NOTE_F7, NOTE_G7,
        0, NOTE_E7, 0, NOTE_C7,
        NOTE_D7, NOTE_B6, 0, 0
    };

    //Mario main them tempo
    int tempo[] = {
        12, 12, 12, 12,
        12, 12, 12, 12,
        12, 12, 12, 12,
        12, 12, 12, 12,

        12, 12, 12, 12,
        12, 12, 12, 12,
        12, 12, 12, 12,
        12, 12, 12, 12,

        9, 9, 9,
        12, 12, 12, 12,
        12, 12, 12, 12,
        12, 12, 12, 12,

        12, 12, 12, 12,
        12, 12, 12, 12,
        12, 12, 12, 12,
        12, 12, 12, 12,

        9, 9, 9,
        12, 12, 12, 12,
        12, 12, 12, 12,
        12, 12, 12, 12,
    };

    //Underworld melody
    int underworld_melody[] = {
        NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
        NOTE_AS3, NOTE_AS4, 0,
        0,
        NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
        NOTE_AS3, NOTE_AS4, 0,
        0,
        NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
        NOTE_DS3, NOTE_DS4, 0,
        0,
        NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
        NOTE_DS3, NOTE_DS4, 0,
        0, NOTE_DS4, NOTE_CS4, NOTE_D4,
        NOTE_CS4, NOTE_DS4,
        NOTE_DS4, NOTE_GS3,
        NOTE_G3, NOTE_CS4,
        NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
        NOTE_GS4, NOTE_DS4, NOTE_B3,
        NOTE_AS3, NOTE_A3, NOTE_GS3,
        0, 0, 0
    };

    //Underworld tempo
    int underworld_tempo[] = {
        12, 12, 12, 12,
        12, 12, 6,
        3,
        12, 12, 12, 12,
        12, 12, 6,
        3,
        12, 12, 12, 12,
        12, 12, 6,
        3,
        12, 12, 12, 12,
        12, 12, 6,
        6, 18, 18, 18,
        6, 6,
        6, 6,
        6, 6,
        18, 18, 18, 18, 18, 18,
        10, 10, 10,
        10, 10, 10,
        3, 3, 3
    };

    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / tempo[thisNote];

        tone(melodyPin, melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        // stop the tone playing:
        noTone(melodyPin);delay(noteDuration);

    }
  

    Serial.println(" 'Underworld Theme'");
    size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / underworld_tempo[thisNote];

        tone(melodyPin, underworld_melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        // stop the tone playing:
        noTone(melodyPin);
        delay(noteDuration);
    }
}

void bella_ciao(int BuzzerPin) {
    int Si2 =1975;
    int LaS2=1864;
    int La2= 1760;
    int SolS2=1661;
    int Sol2=1567;
    int FaS2=1479;
    int Fa2= 1396;
    int Mi2= 1318;
    int ReS2=1244;
    int Re2= 1174;
    int DoS2=1108;
    int Do2= 1046;

    // Low Octave
    int Si = 987;
    int LaS= 932;
    int La = 880;
    int SolS=830;
    int Sol= 783;
    int FaS= 739;
    int Fa=  698;
    int Mi=  659;
    int ReS= 622;
    int Re = 587;
    int DoS =554;
    int Do = 523;

    // define the notes
    int rounda=0;
    int roundp=0;
    int white= 0;
    int whitep=0;
    int black=0;  
    int blackp=0;
    int quaver=0;
    int quaverp =0;
    int semiquaver=0;
    int semiquaverp=0;
    int bpm= 120;

    black= 35000/bpm; 
    blackp=black*1.5;
    white= black*2;
    whitep=white*1.5;
    rounda= black*4;
    roundp= rounda*1.5;
    quaver= black/2;
    quaverp=quaver*1.5;
    semiquaver= black/4;
    semiquaverp=semiquaver*1.5;


    tone(BuzzerPin,Mi,black);
    delay(black+50);
    tone(BuzzerPin,La,black);
    delay(black+50);
    tone(BuzzerPin,Si,black);
    delay(black+50);
    tone(BuzzerPin,Do2,black);
    delay(black+50);
    tone(BuzzerPin,La,black);

    delay(2*white+50);

    tone(BuzzerPin,Mi,black);
    delay(black+50);
    tone(BuzzerPin,La,black);
    delay(black+50);
    tone(BuzzerPin,Si,black);
    delay(black+50);
    tone(BuzzerPin,Do2,black);
    delay(black+50);
    tone(BuzzerPin,La,black);

    delay(2*white+50);

    tone(BuzzerPin,Mi,black);
    delay(black+50);
    tone(BuzzerPin,La,black);
    delay(black+50);
    tone(BuzzerPin,Si,black);
    delay(black+50);
    tone(BuzzerPin,Do2,white*1.3);
    delay(2*black+50);

    tone(BuzzerPin,Si,black);
    delay(black+50);
    tone(BuzzerPin,La,black);
    delay(black+50);
    tone(BuzzerPin,Do2,white*1.3);
    delay(2*black+50);

    tone(BuzzerPin,Si,black);
    delay(black+50);
    tone(BuzzerPin,La,black);
    delay(black+50);
    tone(BuzzerPin,Mi2,black);
    delay(white+50);
    tone(BuzzerPin,Mi2,black);
    delay(white+100);

    tone(BuzzerPin,Mi2,black);
    delay(white+50);
    tone(BuzzerPin,Re2,black);
    delay(black+50);
    tone(BuzzerPin,Mi2,black);
    delay(black+50);
    tone(BuzzerPin,Fa2,black);
    delay(black+50);
    tone(BuzzerPin,Fa2,white*1.3);
    delay(rounda+100);

    tone(BuzzerPin,Fa2,black);
    delay(black+50);
    tone(BuzzerPin,Mi2,black);
    delay(black+50);
    tone(BuzzerPin,Re2,black);
    delay(black+50);
    tone(BuzzerPin,Fa2,black);
    delay(black+50);
    tone(BuzzerPin,Mi2,white*1.3);
    delay(rounda+100);

    tone(BuzzerPin,Mi2,black);
    delay(black+50);
    tone(BuzzerPin,Re2,black);
    delay(black+50);
    tone(BuzzerPin,Do2,black);
    delay(black+50);
    tone(BuzzerPin,Si,white*1.3);
    delay(white+50);
    tone(BuzzerPin,Mi2,white*1.3);
    delay(white+50);
    tone(BuzzerPin,Si,white*1.3);
    delay(white+50);
    tone(BuzzerPin,Do2,white*1.3);
    delay(white+50);
    tone(BuzzerPin,La,rounda*1.3);
    delay(rounda+50);  
}

void christ_song(int buzzer) {

    int melody3[] = {  
        NOTE_C5,4, //1  
        NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,  
        NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,  
        NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,  
        NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,  
        NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,  
        NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,  
        NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,  
        NOTE_F5,2, NOTE_C5,4, //8   
        NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,  
        NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,  
        NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,  
        NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,  
        NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,  
        NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,  
        NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,  
        NOTE_F5,2, NOTE_C5,4,  
        NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,//17  
        NOTE_E5,2, NOTE_E5,4,  
        NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,  
        NOTE_C5,2, NOTE_A5,4,  
        NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,  
        NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,  
        NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,  
        NOTE_F5,2, NOTE_C5,4,   
        NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,  
        NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,  
        NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, //27  
        NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,  
        NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,  
        NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,  
        NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,  
        NOTE_F5,2, NOTE_C5,4,  
        NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,  
        NOTE_E5,2, NOTE_E5,4,  
        NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,  
        NOTE_C5,2, NOTE_A5,4,//36  
        NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,  
        NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,  
        NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,  
        NOTE_F5,2, NOTE_C5,4,   
        NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,  
        NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,  
        NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,   
        NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,  
        NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,//45  
        NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,  
        NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,  
        NOTE_F5,2, NOTE_C5,4,  
        NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,  
        NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,  
        NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,  
        NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,  
        NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, //53  
        NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,  
        NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,  
        NOTE_F5,2, REST,4  
    };  
    int tempo3 = 140; 
    int notes3 = sizeof(melody3) / sizeof(melody3[0]) / 2;  
    int wholenote3 = (60000 * 4) / tempo3;  
    int divider = 0, noteDuration = 0;  
    for (int thisNote = 0; thisNote < notes3 * 2; thisNote = thisNote + 2) {  
        // calculates the duration of each note  
        divider = melody3[thisNote + 1];  
        if (divider > 0) {  
            // regular note, just proceed  
            noteDuration = (wholenote3) / divider;  
        } 
        else if (divider < 0) {  
            // dotted notes are represented with negative durations!!  
            noteDuration = (wholenote3) / abs(divider);  
            noteDuration *= 1.5; // increases the duration in half for dotted notes  
        }  
        // we only play the note for 90% of the duration, leaving 10% as a pause  
        tone(buzzer, melody3[thisNote], noteDuration * 0.9);  
        // Wait for the specief duration before playing the next note.  
        delay(noteDuration);  
        // stop the waveform generation before the next note.  
        noTone(buzzer);  
    }   
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.setTimeout(2000);
    while(!Serial){}
    pinMode(buz_pin, OUTPUT);
    client.setDebug(true);  // Pass a true or false bool value to activate debug messages
    client.wifiConnection(WIFINAME, WIFIPASS);
    client.begin(callback);
    client.ubidotsSubscribe("nodemcu", "tune_to_play"); client.ubidotsSubscribe("nodemcu", "toggle");  // Insert the dataSource and Variable's Labels
}

void loop() {
    // put your main code here, to run repeatedly:
    if (!client.connected()) {
        client.reconnect();
        client.ubidotsSubscribe("nodemcu", "tune_to_play"); client.ubidotsSubscribe("nodemcu", "toggle"); // Insert the dataSource and Variable's Labels
    }

    client.loop();
    if(buzzing && song_to_play == '0')beep_sound(buz_pin);
    else if(song_to_play == '0') noTone(buz_pin);

    if (millis()>30000){
        client.add("toggle",0);
        client.ubidotsPublish("nodemcu");delay(1000);
        Serial.print("I'm awake, but I'm going into deep sleep mode for ");
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.print(20);
        Serial.println(" seconds");
        ESP.deepSleep(10*1e6); 
    }                 

}