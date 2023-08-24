enum Volume: byte {
  UP = 0x02,
  DOWN = 0x03,
  MUTE = 0x09
};

enum Channels: byte {
  NEXT = 0x00,
  PREVIOUS = 0x01,
  FAVORITE = 0x1E,
  BACKWARDS = 0x1A,
  MANAGER = 0x2D,
  LIST = 0x4C,
  RECORDING = 0x90
};

enum Numbers: byte {
  ZERO = 0x10,
  ONE = 0x11,
  TWO = 0x12,
  THREE = 0x13,
  FOUR = 0x14,
  FIVE = 0x15,
  SIX = 0x16,
  SEVEN = 0x17,
  EIGHT = 0x18,
  NINE = 0x19
};

enum Media: byte {
  PLAY = 0xB0,
  PAUSE = 0xBA
};

enum Input: byte {
  DASHBOARD = 0x3E,
  LIVE_TV = 0x0F,
  HDMI_1 = 0xCE,
  HDMI_2 = 0xCC,
  HDMI_3 = 0xE9,
  HDMI_4 = 0xDA
};

enum Apps: byte {
  NETFLIX = 0x56,
  PRIME = 0x5C,
  DISNEY = 0x31,
  MOVIES = 0x81,
  PLUTO = 0x61
};

enum General: byte {
  POWER = 0x08,
  SOURCE = 0x0B,
  TIMER = 0x0E,
  CAPTIONS = 0x38,
  MENU = 0x42,
  SETTINGS = 0x43,
  PICTURE_MODE = 0x4D,
  ASPECT_RATIO = 0x79,
  SIMPLINK = 0x7E,
  ENERGY_SAVER = 0x95,
  EXIT = 0x5B
};

enum Demo: byte {
  MESSAGE = 0x33,
  AI_PICTURE_PRO = 0x11,
  AI_SOUND_PRO = 0x12,
  SOCCER = 0xBB
};

enum Service: byte {
  REMOTE_PARING = 0x75,
  MINI_MENU = 0xEA,
  SCREEN_STATS = 0xFC,
  SOUND_STATS = 0xFD,
  POWER_ONLY = 0xFE,
  EZ_MENU = 0xFF
};
