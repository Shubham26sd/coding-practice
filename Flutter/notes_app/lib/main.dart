import 'package:flutter/material.dart';
import 'package:notes_app/screens/HomeScreen.dart';

// final kLightTheme =

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        fontFamily: 'Cairo',
      ),
      home: HomeScreen(),
    );
  }
}
