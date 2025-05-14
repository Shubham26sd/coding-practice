import 'package:flutter/material.dart';

class NewNote extends StatelessWidget {
  const NewNote({super.key});

  @override
  Widget build(BuildContext context) {
    return const Scaffold(
      body: SafeArea(
        child: Padding(
          padding: EdgeInsets.all(
              16.0), // Optional padding to give some space around
          child: Column(
            children: [
              TextField(
                keyboardType: TextInputType.name,
                decoration: InputDecoration(
                  border: OutlineInputBorder(),
                  hintText: 'Enter a search term',
                ),
              ),
              Row(
                children: [],
              )
            ],
          ),
        ),
      ),
    );
  }
}
