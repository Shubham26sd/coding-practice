import 'package:flutter/material.dart';
import 'package:adv_basics/styled_text.dart';

class quiz extends StatelessWidget {
  const quiz({super.key});

  @override
  Widget build(context) {
    return Column(
      mainAxisSize: MainAxisSize.min,
      children: [
        Image.asset('assets/images/quiz-logo.png'),
        const SizedBox(height: 20),
        const StyledText('Learn Flutter the fun way!'),
        const SizedBox(height: 20),
        TextButton(
          onPressed: () {},
          style: TextButton.styleFrom(
            foregroundColor: Colors.white,
            textStyle: const TextStyle(
              fontSize: 28,
            ),
          ),
          child: const Text('Start Quiz'),
        )
      ],
    );
  }
}
