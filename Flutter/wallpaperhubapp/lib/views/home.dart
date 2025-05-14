import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'package:wallpaperhubapp/data/data.dart';
import 'package:wallpaperhubapp/model/categories_model.dart';
import 'package:wallpaperhubapp/model/wallpaper_model.dart';
import 'package:wallpaperhubapp/views/categories.dart';
import 'package:wallpaperhubapp/views/search.dart';
import 'package:wallpaperhubapp/widgets/widget.dart';

class Home extends StatefulWidget {
  const Home({Key? key}) : super(key: key);

  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  List<CategorieModel> categories = [];
  List<WallpaperModel> wallpapers = [];

  TextEditingController searchController = TextEditingController();
  ScrollController _scrollController = ScrollController();
  int noOfImageToLoad = 20;
  bool _isLoading = false;

  @override
  void initState() {
    super.initState();
    getTrendingWallpapers();
    _scrollController.addListener(_scrollListener);
  }

  @override
  void dispose() {
    _scrollController.dispose();
    super.dispose();
  }

  void _scrollListener() {
    if (_scrollController.position.pixels == _scrollController.position.maxScrollExtent) {
      if (!_isLoading) {
        setState(() {
          _isLoading = true;
        });
        noOfImageToLoad += 20;
        getTrendingWallpapers();
      }
    }
  }

  Future<void> getTrendingWallpapers() async {
    final url = Uri.parse(
        "https://api.pexels.com/v1/curated?per_page=$noOfImageToLoad");

    var response = await http.get(url, headers: {"Authorization": apikey});

    Map<String, dynamic> jsonData = json.decode(response.body);
    List<WallpaperModel> newWallpapers = [];

    jsonData["photos"].forEach((element) {
      WallpaperModel wallpaperModel = WallpaperModel.fromMap(element);
      newWallpapers.add(wallpaperModel);
    });

    setState(() {
      _isLoading = false;
      wallpapers = newWallpapers;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      appBar: AppBar(
        elevation: 0.0,
        title: brandName(),
      ),
      body: SingleChildScrollView(
        controller: _scrollController,
        child: Container(
          child: Column(
            children: <Widget>[
              Container(
                decoration: BoxDecoration(
                  color: const Color(0xfff5f8fd),
                  borderRadius: BorderRadius.circular(30),
                ),
                padding: const EdgeInsets.symmetric(horizontal: 24),
                margin: const EdgeInsets.symmetric(horizontal: 24),
                child: Row(
                  children: [
                    Expanded(
                      child: TextField(
                        controller: searchController,
                        decoration: const InputDecoration(
                            hintText: "search wallpaper",
                            border: InputBorder.none),
                      ),
                    ),
                    InkWell(
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => Search(
                              searchQuerry: searchController.text,
                            ),
                          ),
                        );
                      },
                      child: const Icon(Icons.search),
                    ),
                  ],
                ),
              ),
              const SizedBox(height: 16),
              Container(
                height: 80,
                child: ListView.builder(
                    padding: const EdgeInsets.symmetric(horizontal: 24),
                    scrollDirection: Axis.horizontal,
                    itemCount: categories.length,
                    shrinkWrap: true,
                    itemBuilder: (context, index) {
                      return CategoriesTile(
                        title: categories[index].categorieName,
                        imgUrl: categories[index].imgUrl,
                      );
                    }),
              ),
              wallpapersList(wallpapers, context),
              if (_isLoading)
                Container(
                  padding: EdgeInsets.symmetric(vertical: 10),
                  child: Center(child: CircularProgressIndicator()),
                ),
            ],
          ),
        ),
      ),
    );
  }
}

class CategoriesTile extends StatelessWidget {
  final String imgUrl, title;

  const CategoriesTile({
    required this.imgUrl,
    required this.title,
  });

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () {
        Navigator.push(
          context,
          MaterialPageRoute(
            builder: (context) => Categorie(
              categorieName: title.toLowerCase(),
            ),
          ),
        );
      },
      child: Container(
        margin: const EdgeInsets.only(right: 4),
        child: Stack(
          children: [
            ClipRRect(
              borderRadius: BorderRadius.circular(8),
              child: Image.network(
                imgUrl,
                height: 50,
                width: 100,
                fit: BoxFit.cover,
              ),
            ),
            Container(
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(8),
                color: Colors.black26,
              ),
              height: 50,
              width: 100,
              alignment: Alignment.center,
              child: Text(
                title,
                style: const TextStyle(
                  color: Colors.white,
                  fontWeight: FontWeight.w500,
                  fontSize: 16,
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
