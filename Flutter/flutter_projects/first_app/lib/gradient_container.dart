import 'package:flutter/material.dart';
import 'package:first_app/dice_roller.dart';
// import 'package:first_app/styled_text.dart';

// Alignment? startAlignment; and later initialise startAlignment = Alignment.topLeft;
const startAlignment = Alignment.topLeft;
const endAlignment = Alignment.bottomRight;

class GradientContainer extends StatelessWidget {
  // const GradientContainer({super.key, required this.colors});
  //accept a named argument called key and forward it automatically to super class
  // GradientContainer({key}) : super(key: key);   OR
  const GradientContainer(this.color1, this.color2, {super.key});

//constructor function
  const GradientContainer.purple({super.key})
      : color1 = Colors.deepPurple,
        color2 = Colors.indigo;

  final Color color1;
  final Color color2;

  @override
  Widget build(context) {
    return Container(
      decoration: BoxDecoration(
        gradient: LinearGradient(
          colors: [color1, color2],
          begin: startAlignment,
          end: endAlignment,
        ),
      ),
      child: const Center(
        child: DiceRoller(),
      ),
    );
  }
  // @override
  // Widget build(context) {
  //   return Container(
  //     decoration: BoxDecoration(
  //       gradient: LinearGradient(
  //         colors: colors,
  //         begin: startAlignment,
  //         end: endAlignment,
  //       ),
  //     ),
  //     child: const Center(child: StyledText('Shubham ka app')),
  //   );
  // }
}


//backgroundColor: Color.fromARGB(255, 41, 223, 180),