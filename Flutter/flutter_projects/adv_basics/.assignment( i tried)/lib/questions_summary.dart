import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';

class QuestionsSummary extends StatelessWidget {
  const QuestionsSummary(this.summaryData, {super.key});

  final List<Map<String, Object>> summaryData;

  @override
  Widget build(context) {
    return SizedBox(
      height: 300,
      child: SingleChildScrollView(
        child: Column(
          children: summaryData.map((data) {
            return Row(
              children: [
                Text(((data['question_index'] as int) + 1).toString()),
                Expanded(
                  child: Column(
                    children: [
                      Text(
                        data['question'] as String,
                        style: const TextStyle(
                          color: Colors.white,
                          fontSize: 20,
                        ),
                        textAlign: TextAlign.left,
                      ),
                      const SizedBox(height: 5),
                      Text(
                        data['user_answer'] as String,
                        style: const TextStyle(
                          color: Colors.white,
                          fontSize: 20,
                        ),
                        textAlign: TextAlign.left,
                      ),
                      Text(
                        data['correct_answer'] as String,
                        style: const TextStyle(
                          fontSize: 20,
                        ),
                        textAlign: TextAlign.left,
                      ),
                    ],
                  ),
                ),
              ],
            );
          }).toList(),
        ),
      ),
    );
  }
}
