import 'package:flutter/material.dart';
import 'package:wallpaperhubapp/model/wallpaper_model.dart';
import 'package:wallpaperhubapp/views/image_view.dart';

Widget brandName() {
  return const Row(
    mainAxisAlignment: MainAxisAlignment.center,
    children: <Widget>[
      Text(
        'Wallpaper',
        style: TextStyle(color: Colors.black87),
      ),
      Text(
        'Hub',
        style: TextStyle(color: Colors.blue),
      ),
    ],
  );
}

Widget wallpapersList(List<WallpaperModel> wallpapers, context) {
  return Container(
    padding: const EdgeInsets.symmetric(horizontal: 16),
    child: GridView.count(
      shrinkWrap: true,
      physics: ClampingScrollPhysics(),
      crossAxisCount: 2,
      childAspectRatio: 0.6,
      mainAxisSpacing: 6.0,
      crossAxisSpacing: 6.0,
      children: wallpapers.map((wallpaper) {
        return GridTile(
          child: GestureDetector(
            onTap: () {
              Navigator.push(
                context,
                MaterialPageRoute(
                  builder: (context) =>
                      ImageView(imgUrl: wallpaper.src.portrait),
                ),
              );
            },
            child: Hero(
              tag: wallpaper.src.portrait,
              child: Container(
                child: ClipRRect(
                  borderRadius: BorderRadius.circular(16),
                  child: Image.network(
                    wallpaper.src.portrait,
                    fit: BoxFit.cover,
                  ),
                ),
              ),
            ),
          ),
        );
      }).toList(),
    ),
  );
}
