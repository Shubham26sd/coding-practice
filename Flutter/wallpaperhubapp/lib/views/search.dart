import "dart:convert";

import "package:flutter/material.dart";
import "package:wallpaperhubapp/data/data.dart";
import "package:wallpaperhubapp/model/wallpaper_model.dart";
import "package:wallpaperhubapp/widgets/widget.dart";
import 'package:http/http.dart' as http;

class Search extends StatefulWidget {
  const Search({
    super.key,
    required this.searchQuerry,
  });

  final String searchQuerry;

  @override
  State<Search> createState() => _SearchState();
}

class _SearchState extends State<Search> {
  final ScrollController _scrollController = ScrollController();
  int noOfImageToLoad = 10;
  List<WallpaperModel> wallpapers = [];
  bool isLoading = false;

  @override
  void initState() {
    super.initState();
    searchController.text = widget.searchQuerry;
    getSearchWallpapers(widget.searchQuerry);
    _scrollController.addListener(_scrollListener);
  }

  @override
  void dispose() {
    _scrollController.dispose();
    super.dispose();
  }

  void _scrollListener() {
    if (_scrollController.position.pixels ==
        _scrollController.position.maxScrollExtent) {
      noOfImageToLoad += 10;
      getSearchWallpapers(widget.searchQuerry);
    }
  }

  TextEditingController searchController = TextEditingController();

  Future<void> getSearchWallpapers(String query) async {
    setState(() {
      isLoading = true;
    });

    final url = Uri.parse(
        "https://api.pexels.com/v1/search?query=$query&per_page=$noOfImageToLoad&&page=1");

    var response = await http.get(url, headers: {"Authorization": apikey});

    // Check if the response is successful and body is not null
    if (response.statusCode == 200) {
      Map<String, dynamic> jsonData = json.decode(response.body);
      List<WallpaperModel> newWallpapers = [];
      jsonData["photos"].forEach((element) {
        WallpaperModel wallpaperModel = WallpaperModel.fromMap(element);
        newWallpapers.add(wallpaperModel);
      });

      setState(() {
        wallpapers.addAll(newWallpapers);
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        elevation: 0.0,
        title: brandName(),
      ),
      body: SingleChildScrollView(
        controller: _scrollController,
        child: Container(
          child: Column(
            children: [
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
                          border: InputBorder.none,
                        ),
                      ),
                    ),
                    InkWell(
                      onTap: () {
                        getSearchWallpapers(searchController.text);
                      },
                      child: const Icon(Icons.search),
                    ),
                  ],
                ),
              ),
              const SizedBox(height: 16),
              wallpapersList(wallpapers, context),
              Container(
                height: 40,
                child: isLoading ? CircularProgressIndicator() : null,
              )
            ],
          ),
        ),
      ),
    );
  }
}
