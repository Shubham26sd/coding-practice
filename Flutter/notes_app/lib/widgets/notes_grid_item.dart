import 'package:flutter/material.dart';
import 'package:notes_app/model/note.dart';

class NotesGridItem extends StatelessWidget {
  const NotesGridItem({
    super.key,
    required this.item,
  });

  final Note item;

  @override
  Widget build(BuildContext context) {
    final colorItem = item.color;

    return ClipRRect(
      borderRadius: BorderRadius.circular(16),
      child: Material(
        child: InkWell(
          onTap: () {},
          splashColor: Colors.transparent,
          child: Container(
            margin: const EdgeInsets.symmetric(vertical: 5, horizontal: 7),
            padding: const EdgeInsets.all(16),
            decoration: BoxDecoration(
              color: colorItem,
              borderRadius: BorderRadius.circular(16),
            ),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.center,
              mainAxisAlignment: MainAxisAlignment.start,
              children: [
                Text(item.title),
                const SizedBox(height: 20),
                Text(item.body),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
