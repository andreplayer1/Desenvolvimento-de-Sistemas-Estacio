import 'package:flutter/material.dart';

class HomeView extends StatelessWidget {
  const HomeView({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Menu de Opções'),
        backgroundColor: Colors.blue,
      ),
      body: const Center(
        child: Text(
          'Aqui vai entra meu menu!',
          style: TextStyle(fontSize: 20),
        )
      ),
    );
  }
}