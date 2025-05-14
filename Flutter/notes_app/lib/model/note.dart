import 'package:flutter/material.dart';

class Note {
  const Note({
    required this.title,
    required this.body,
    required this.color,
  });
  final String title;
  final String body;
  final Color color;
}
