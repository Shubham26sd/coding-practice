import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

class LyricsScreen extends StatefulWidget {
  const LyricsScreen({
    super.key,
    required this.title,
    required this.heroTag,
    required this.url,
    required this.lyrics,
  });

  final String title;
  final String heroTag;
  final String url;
  final String lyrics;

  @override
  State<LyricsScreen> createState() => _LyricsScreenState();
}

class _LyricsScreenState extends State<LyricsScreen> {
  bool _showLyrics = false;

  @override
  void initState() {
    super.initState();
    Future.delayed(Duration(milliseconds: 400), () {
      setState(() {
        _showLyrics = true;
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Hero(
      tag: widget.heroTag,
      child: Material(
        type: MaterialType.transparency,
        child: Stack(
          children: [
            ClipRRect(
              child: Image.network(
                widget.url,
                height: MediaQuery.of(context).size.height,
                width: MediaQuery.of(context).size.width,
                fit: BoxFit.contain,
              ),
            ),
            Container(
              color: Colors.black.withOpacity(0.8),
            ),
            Scaffold(
              backgroundColor: Colors.transparent,
              appBar: AppBar(
                backgroundColor: Colors.transparent,
                foregroundColor: Colors.white,
                title: Text(widget.title),
              ),
              body: SingleChildScrollView(
                padding: const EdgeInsets.all(18.0),
                child: AnimatedOpacity(
                  opacity: _showLyrics ? 1.0 : 0.0,
                  duration: Duration(milliseconds: 300),
                  curve: Curves.easeIn,
                  child: Column(
                    children: [
                      Text(
                        "Lyrics",
                        style: GoogleFonts.arefRuqaaInk(
                          color: Colors.white,
                          fontSize: 25,
                          fontWeight: FontWeight.w700,
                          height: 2,
                        ),
                      ),
                      Text(
                        widget.lyrics,
                        style: GoogleFonts.arefRuqaaInk(
                            color: Colors.white, fontSize: 18, height: 2),
                      ),
                    ],
                  ),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
