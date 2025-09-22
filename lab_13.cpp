// COMSC210 | Lab 12 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constants
const int playlist_size = 52;
const string filename = "songs.txt";

// Song struct that holds different attributes of a song
struct Song {
  std::string name;
  std::string genre;
  std::string artist;
  int weekNumber;
};

// Function prototypes
void readSongs(vector<Song>& playlist, const string& songs);
void displaySongs(const vector<Song>& playlist);
void analyzePlaylist(const vector<Song>& playlist);

// Function: Loads song data from 'songs.txt' into the playlist vector we
// initialized
// argument: playlist vector reference, filename string
// returns: nothing
void readSongs(vector<Song>& playlist, const string& songs) {
  ifstream file(songs);

  if (!file.is_open()) {
    cout << "Error: Could not open file '" << songs
         << "'. Please check the file name and try again.\n";
    return;
  }

  Song s;
  while (file >> s.name >> s.genre >> s.artist >> s.weekNumber) {
    if (s.weekNumber < 1 || s.weekNumber > playlist_size) {
      cout << "Invalid week number at " << s.weekNumber
           << ". Skipping entry. \n"
           << endl;
    } else {
      playlist.push_back(s);
    }
  }
  file.close();
}

// Function: Prints songs in the playlist
// argument: playlist vector reference
// returns: nothing
void displaySongs(const vector<Song>& playlist) {
  cout << "Weekly Playlist!\n";
  for (const auto& song : playlist) {
    if (!song.name.empty()) {
      cout << "Week" << song.weekNumber << ": " << song.name << "  by "
           << song.artist << " [" << song.genre << "]\n";
    }
  }
}

// Function: Analyze the playlist on certain measures while using the std:vector
// member functions argument: playlist vector reference returns: nothing
void analyzePlaylist(const vector<Song>& playlist) {
  cout << "Playlist Wrapped:\n";

  int week = 1;
  for (const auto& song : playlist) {
    cout << "Week " << week << ":" << song.name << endl;
    week++;
  }
  cout << "Total capacity: " << playlist.size() << endl;
  cout << "Is playlist empty? ";
  if (playlist.empty()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  cout << "First song: " << playlist.front().name << endl;
  cout << "Last song: " << playlist.back().name << endl;
}

int main() {
  // initialized a playlist vector
  vector<Song> playlist{};
  // Passing playlist throught the functions
  readSongs(playlist, filename);
  displaySongs(playlist);
  analyzePlaylist(playlist);

  return 0;
}