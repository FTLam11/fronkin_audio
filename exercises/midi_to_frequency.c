#include <stdio.h>
#include <math.h>

/*
 * Going up or down an octave changes the frequency by a factor of 2
 * One octave = 12 intervals, so changing one interval results in 2 ^ 1/12
 * change in frequency
 * */
double INTERVAL_RATIO() {
  return pow(2, 1.0/12);
}

/* Returns frequency of MIDI note 0 */
double base_frequency() {
  /*
   * Concert A has a frequency of 440 Hz and is MIDI note 69
   * Middle A is one octave lower than Concert A and is MIDI note 57
   * Middle C is three intervals higher than Middle A and is MIDI note 60
   * */
  const int MIDDLE_A = 220;
  const double MIDDLE_C = MIDDLE_A * pow(INTERVAL_RATIO(), 3);

  /*
   * Go down 5 octaves to find MIDI note 0, having frequency each time
   * */
  return MIDDLE_C * pow(0.5, 5);
}

/* Returns frequency of a MIDI note (0-127) */
double midi_note_to_frequency(int midi_note) {
  return base_frequency() * pow(INTERVAL_RATIO(), midi_note);
}

/* Given a MIDI note, calculate the equivalent frequency */
int main(int _argc, char *argv[]) {
  int midi_note;

  sscanf(argv[1], "%d", &midi_note);

  printf("%f", midi_note_to_frequency(midi_note));

  return 0;
}
