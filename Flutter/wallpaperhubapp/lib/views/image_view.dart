import 'package:flutter/material.dart';
import 'package:gallery_saver_plus/gallery_saver.dart';

class ImageView extends StatefulWidget {
  const ImageView({
    super.key,
    required this.imgUrl,
  });
  final String imgUrl;

  @override
  State<ImageView> createState() => _ImageViewState();
}

class _ImageViewState extends State<ImageView> {
  // var filePath;
  bool saved = false;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(
        children: [
          Hero(
            tag: widget.imgUrl,
            child: Container(
              height: MediaQuery.of(context).size.height,
              width: MediaQuery.of(context).size.width,
              child: Image.network(
                widget.imgUrl,
                fit: BoxFit.cover,
              ),
            ),
          ),
          Container(
            height: MediaQuery.of(context).size.height,
            width: MediaQuery.of(context).size.width,
            alignment: Alignment.bottomCenter,
            child: Column(
              mainAxisAlignment: MainAxisAlignment.end,
              children: [
                GestureDetector(
                  onTap: () async {
                    String url = widget.imgUrl;
                    GallerySaver.saveImage(
                      url,
                      toDcim: true,
                      albumName: "WallpaperHub",
                    );
                    setState(() {
                      saved = true;
                    });
                    showDialog(
                      context: context,
                      builder: (BuildContext context) {
                        return AlertDialog(
                          title: const Text('Saving...'),
                          content: const Text(
                              'Image will be saved to gallery in a few seconds'),
                          actions: <Widget>[
                            TextButton(
                              onPressed: () {
                                Navigator.of(context).pop();
                              },
                              child: const Text('OK'),
                            ),
                          ],
                        );
                      },
                    );
                  },
                  child: Stack(
                    children: [
                      // Container(
                      //   width: MediaQuery.of(context).size.width / 2,
                      //   height: 58,
                      //   color: const Color(0xff1C1B1B).withOpacity(0.8),
                      // ),
                      Container(
                        width: MediaQuery.of(context).size.width / 2,
                        padding: const EdgeInsets.symmetric(
                            horizontal: 8, vertical: 8),
                        decoration: BoxDecoration(
                          border: Border.all(color: Colors.white60, width: 1),
                          borderRadius: BorderRadius.circular(30),
                          gradient: const LinearGradient(
                            colors: [
                              Color(0x36FFFFFF),
                              Color(0x0FFFFFFF),
                            ],
                          ),
                        ),
                        child: const Column(
                          children: [
                            Text(
                              "Set Wallpaper",
                              style: TextStyle(
                                  fontSize: 16, color: Colors.white54),
                            ),
                            Text(
                              "Image will be saved in gallery",
                              style: TextStyle(
                                  fontSize: 12, color: Colors.white54),
                            ),
                          ],
                        ),
                      ),
                    ],
                  ),
                ),
                const SizedBox(height: 16),
                GestureDetector(
                  onTap: () {
                    Navigator.pop(context);
                  },
                  child: const Text(
                    "Cancel",
                    style: TextStyle(color: Colors.white),
                  ),
                ),
                // ignore: prefer_const_constructors
                SizedBox(height: 50),
              ],
            ),
          ),
        ],
      ),
    );
  }
}
