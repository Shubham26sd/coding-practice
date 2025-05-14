import 'package:flutter/material.dart';
import 'package:notes_app/data/note_items.dart';
import 'package:notes_app/screens/new_note.dart';
import 'package:notes_app/widgets/notes_grid_item.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  void changeScreen(BuildContext context) {
    Navigator.of(context).push(
      MaterialPageRoute(builder: (ctx) => const NewNote()),
    );
  }

  @override
  Widget build(BuildContext context) {
    // var size = MediaQuery.of(context).size.height;
    return Scaffold(
      appBar: AppBar(
        centerTitle: true,
        shape:
            ContinuousRectangleBorder(borderRadius: BorderRadius.circular(80)),
        title: const Text(
          'Notes App',
          style:
              TextStyle(fontFamily: 'Cairo-Bold', fontWeight: FontWeight.w600),
        ),
        backgroundColor: const Color.fromRGBO(172, 225, 175, 1),
        actions: [
          IconButton(
            onPressed: () => changeScreen(context),
            icon: const Icon(Icons.add),
          ),
        ],
      ),
      backgroundColor: const Color.fromRGBO(224, 251, 226, 1),
      body: const ItemGrid(),
      bottomNavigationBar: const BottomAppBar(
        height: 70,
        color: Color.fromARGB(255, 33, 243, 128),
      ),
    );
  }
}

class ItemGrid extends StatefulWidget {
  const ItemGrid({
    super.key,
  });

  @override
  State<ItemGrid> createState() => _ItemGridState();
}

class _ItemGridState extends State<ItemGrid> {
  @override
  Widget build(BuildContext context) {
    return GridView.count(
      crossAxisCount: 2,
      children: [for (final item in notes) NotesGridItem(item: item)],
      padding: EdgeInsets.only(left: 10, right: 10),
    );
  }
}
