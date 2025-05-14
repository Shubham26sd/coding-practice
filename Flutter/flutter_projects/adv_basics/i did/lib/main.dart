import 'package:flutter/material.dart';
import 'package:adv_basics/gradientContainer.dart';

void main() {
  runApp(const MaterialApp(
    home: Scaffold(
      body: GradientContainer(
          Color.fromARGB(167, 226, 34, 34), Color.fromARGB(255, 11, 13, 100)),
    ),
  ));
}
