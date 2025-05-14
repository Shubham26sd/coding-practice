import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:http/http.dart' as http;

class LyricsWidget extends StatelessWidget {
  const LyricsWidget({
    super.key,
    required this.artist,
    required this.title,
    required this.onCopied,
  });

  final artist;
  final title;
  final Function(String) onCopied;

  Future<String> getLyrics(String artist, String title) async {
    final String baseUrl = "https://api.lyrics.ovh/v1/";

    final response = await http.get(Uri.parse('$baseUrl$artist/$title'));

    if (response.statusCode == 200) {
      final data = jsonDecode(response.body);
      onCopied(data['lyrics'].toString());
      return data['lyrics'];
    } else {
      return "No lyrics found";
    }
  }

  @override
  Widget build(BuildContext context) {
    return Container(
        child: FutureBuilder(
      future: getLyrics(artist, title),
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) {
          return CircularProgressIndicator();
        } else if (snapshot.hasError) {
          return Text("Error:  ${snapshot.error}");
        } else {
          return Padding(
            padding: EdgeInsets.all(20),
            child: Container(
              child: SelectableText(
                snapshot.data!,
                style: GoogleFonts.arefRuqaaInk(
                    color: Colors.white, fontSize: 18, height: 1.7),
              ),
            ),
          );
        }
      },
    ));
  }
}
