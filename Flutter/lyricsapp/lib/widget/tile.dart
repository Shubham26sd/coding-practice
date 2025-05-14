import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:lyricsapp/screens/lyrics_screen.dart';

class Tile extends StatelessWidget {
  const Tile({
    super.key,
    required this.artist,
    required this.songName,
    required this.lyrics,
    required this.imgUrl,
    required this.index,
  });

  final String artist;
  final String songName;
  final String lyrics;
  final String imgUrl;
  final index;

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.all(8),
      padding: const EdgeInsets.only(bottom: 10),
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(30),
        color: const Color.fromARGB(255, 21, 23, 22),
      ),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.end,
        children: [
          const SizedBox(height: 10),
          Expanded(
            child: Container(
              margin: const EdgeInsets.symmetric(horizontal: 9),
              child: Hero(
                tag: '$index',
                child: GestureDetector(
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (ctx) => LyricsScreen(
                          title: songName,
                          heroTag: '$index',
                          url: imgUrl,
                          lyrics: lyrics,
                        ),
                      ),
                    );
                  },
                  child: ClipRRect(
                    borderRadius: const BorderRadius.all(Radius.circular(40)),
                    child: Image.network(
                      imgUrl,
                      fit: BoxFit.cover,
                    ),
                  ),
                ),
              ),
            ),
          ),
          const SizedBox(height: 12),
          GestureDetector(
            onTap: () {
              Navigator.push(
                context,
                MaterialPageRoute(
                  builder: (ctx) => LyricsScreen(
                    title: songName,
                    heroTag: '$index',
                    url: imgUrl,
                    lyrics: lyrics,
                  ),
                ),
              );
            },
            child: Column(
              children: [
                Text(
                  songName,
                  style: GoogleFonts.arapey(
                    color: Colors.white,
                    fontWeight: FontWeight.w500,
                    fontSize: 16,
                  ),
                  textAlign: TextAlign.center,
                ),
                Text(
                  artist,
                  style: GoogleFonts.crimsonText(
                    color: Colors.white,
                    fontSize: 11,
                  ),
                  maxLines: 1,
                  overflow: TextOverflow.ellipsis,
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}
