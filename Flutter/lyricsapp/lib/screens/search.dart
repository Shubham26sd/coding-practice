import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:lyricsapp/widget/lyrics.dart';

class Search extends StatefulWidget {
  const Search({super.key});

  @override
  State<Search> createState() => _SearchState();
}

class _SearchState extends State<Search> {
  TextEditingController _artistController = TextEditingController();
  TextEditingController _titleController = TextEditingController();

  Widget lyricsBox = Container();
  final _formkey = GlobalKey<FormState>();
  bool isValid = false;
  bool isCopied = false;
  String lyrics = "";

  void updatedLyrics(String newLyrics) {
    setState(() {
      lyrics = newLyrics;
    });
  }

  @override
  void dispose() {
    _artistController.dispose();
    _titleController.dispose();

    super.dispose();
  }

  void copyToClipboard(String text) {
    Clipboard.setData(ClipboardData(text: text)).then((_) {
      // Optionally show a message or a Snackbar to confirm the copy action
      print('Text copied to clipboard: $text');
    });
  }

  void _toggleCopied() {
    setState(() {
      isCopied = !isCopied;
    });

    ScaffoldMessenger.of(context).clearSnackBars();
    isCopied
        ? ScaffoldMessenger.of(context).showSnackBar(
            SnackBar(
              content: Text("Copied to clipboard"),
            ),
          )
        : null;

    if (isCopied) {
      copyToClipboard(lyrics);
    }
  }

  void _submitForm() {
    if (_formkey.currentState!.validate()) {
      setState(() {
        isValid = true;
        lyricsBox = LyricsWidget(
          //testing
          artist: _artistController.text,
          title: _titleController.text,
          onCopied: updatedLyrics,
        );
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      top: true,
      child: Padding(
        padding: EdgeInsets.only(top: MediaQuery.of(context).padding.top),
        child: Scaffold(
          backgroundColor: Colors.black,
          appBar: AppBar(
            backgroundColor: Colors.black,
            foregroundColor: Colors.white,
            centerTitle: true,
            title: Text(
              "Search Lyrics",
              style: GoogleFonts.crimsonText(
                fontSize: 30,
              ),
            ),
          ),
          body: SingleChildScrollView(
            child: Padding(
              padding: EdgeInsets.only(top: MediaQuery.of(context).padding.top),
              child: Column(
                children: [
                  Container(
                    padding: const EdgeInsets.symmetric(horizontal: 20),
                    child: Form(
                      key: _formkey,
                      child: Column(
                        children: [
                          TextFormField(
                            controller: _artistController,
                            autocorrect: true,
                            keyboardType: TextInputType.name,
                            cursorColor: Colors.white,
                            decoration: InputDecoration(
                              hintText: "Enter Artist Name",
                              hintStyle: TextStyle(color: Colors.white),
                              filled: true,
                              fillColor: Color.fromARGB(211, 99, 99, 99),
                              border: OutlineInputBorder(
                                borderRadius: BorderRadius.circular(30),
                                borderSide: BorderSide.none,
                              ),
                              contentPadding: EdgeInsets.symmetric(
                                  vertical: 18, horizontal: 20),
                            ),
                            validator: (value) {
                              if (value == null || value.isEmpty) {
                                return "Enter a valid artist name";
                              } else {
                                return null;
                              }
                            },
                          ),
                          SizedBox(height: 20),
                          TextFormField(
                            controller: _titleController,
                            autocorrect: true,
                            keyboardType: TextInputType.name,
                            cursorColor: Colors.white,
                            decoration: InputDecoration(
                              hintText: "Enter Song",
                              hintStyle: TextStyle(color: Colors.white),
                              filled: true,
                              fillColor: Color.fromARGB(211, 99, 99, 99),
                              border: OutlineInputBorder(
                                borderRadius: BorderRadius.circular(30),
                                borderSide: BorderSide.none,
                              ),
                              contentPadding: EdgeInsets.symmetric(
                                  vertical: 18, horizontal: 20),
                            ),
                            validator: (value) {
                              if (value == null || value.isEmpty) {
                                return "Enter a valid song name";
                              } else {
                                return null;
                              }
                            },
                          ),
                          const SizedBox(height: 30),
                          Row(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: [
                              ElevatedButton(
                                onPressed: () {
                                  FocusScope.of(context).unfocus();
                                  _submitForm();
                                },
                                child: Icon(
                                  Icons.search,
                                  color: Colors.blueGrey,
                                ),
                              ),
                              const SizedBox(width: 20),
                              ElevatedButton(
                                onPressed: isValid ? _toggleCopied : () {},
                                child: isCopied
                                    ? Icon(
                                        Icons.check_circle,
                                        color: Colors.blueGrey,
                                      )
                                    : Icon(
                                        Icons.copy,
                                        color: Colors.blueGrey,
                                      ),
                              ),
                            ],
                          ),
                        ],
                      ),
                    ),
                  ),
                  lyricsBox,
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}
