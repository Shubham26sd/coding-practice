import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:lyricsapp/data/songs.dart';
import 'package:lyricsapp/screens/search.dart';
import 'package:lyricsapp/widget/tile.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}


class _HomeScreenState extends State<HomeScreen> {
  @override
  Widget build(BuildContext context) {
    return Container(
      color: const Color.fromARGB(255, 0, 0, 0),
      child: SafeArea(
        child: Padding(
          padding: const EdgeInsets.only(top: 20),
          child: Scaffold(
            backgroundColor: const Color.fromARGB(255, 0, 0, 0),
            appBar: AppBar(
              backgroundColor: const Color.fromARGB(255, 0, 0, 0),
              title: const Text(
                "LyricsApp",
                style: TextStyle(
                  color: Colors.white,
                  fontWeight: FontWeight.w700,
                  fontSize: 30,
                ),
              ),
              actions: [
                IconButton(
                  onPressed: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => Search(),
                      ),
                    );
                  },
                  icon: Icon(
                    Icons.search,
                    size: 30,
                  ),
                ),
                const SizedBox(
                  width: 25,
                )
              ],
              titleSpacing: MediaQuery.of(context).size.width * 0.08,
            ),
            body: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                const SizedBox(height: 20),
                Container(
                  margin: const EdgeInsets.only(left: 20),
                  child: Text(
                    "  CIGARETTES AFTER SEX >",
                    style: GoogleFonts.crimsonText(
                      color: Colors.white54,
                      fontSize: 20,
                    ),
                  ),
                ),
                const SizedBox(
                  height: 20,
                ),
                const Expanded(
                  child: Grid(),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}

class Grid extends StatelessWidget {
  const Grid({
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return GridView.builder(
      gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
        crossAxisCount: 2,
        // childAspectRatio: 0.8,
        mainAxisExtent: 300,
      ),
      itemCount: Songs.data.length,
      shrinkWrap: true,
      itemBuilder: (context, index) => Tile(
        songName: Songs.data[index].songName,
        artist: Songs.data[index].artist,
        lyrics: Songs.data[index].lyrics,
        imgUrl: Songs.data[index].imgUrl,
        index: index,
      ),
    );
  }
}
