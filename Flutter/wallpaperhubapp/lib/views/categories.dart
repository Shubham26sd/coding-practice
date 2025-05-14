import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'package:wallpaperhubapp/data/data.dart';
import 'package:wallpaperhubapp/model/wallpaper_model.dart';
import 'package:wallpaperhubapp/widgets/widget.dart';

class Categorie extends StatefulWidget {
  const Categorie({
    super.key,
    required this.categorieName,
  });
  final String categorieName;

  @override
  State<Categorie> createState() => _CategorieState();
}

class _CategorieState extends State<Categorie> {
  List<WallpaperModel> wallpapers = [];

  Future<void> getSearchWallpapers(String querry) async {
    final url = Uri.parse(
        "https://api.pexels.com/v1/search?query=$querry&per_page=15&&page=1");

    var response = await http.get(url, headers: {"Authorization": apikey});

    // print(response.body.toString());

    Map<String, dynamic> jsonData = json.decode(response.body);
    jsonData["photos"].forEach((elememt) {
      // print(elememt);
      WallpaperModel wallpaperModel;
      wallpaperModel = WallpaperModel.fromMap(elememt);
      wallpapers.add(wallpaperModel);
    });

    setState(() {});
  }

  @override
  void initState() {
    getSearchWallpapers(widget.categorieName);
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        elevation: 0.0,
        title: brandName(),
      ),
      body: SingleChildScrollView(
        child: Container(
          child: Column(
            children: [
              const SizedBox(height: 16),
              wallpapersList(wallpapers, context),
            ],
          ),
        ),
      ),
    );
  }
}
