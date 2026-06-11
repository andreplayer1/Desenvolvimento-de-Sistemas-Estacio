import 'package:flutter/material.dart';

void main() {
  runApp(const QuestLogApp());
}

class QuestLogApp extends StatelessWidget {
  const QuestLogApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Quest Log',
      theme: ThemeData.dark(),
      home: const TelaMissoes(),
    );
  }
}

class TelaMissoes extends StatefulWidget {
  const TelaMissoes({super.key});

  @override
  State<TelaMissoes> createState() => _TelaMissoesState();
}

class _TelaMissoesState extends State<TelaMissoes> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Minhas Quests'), centerTitle: true),

      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: const [
            Text('Lista de missões vazia.', style: TextStyle(fontSize: 18)),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          print('Botão de nova Quest clicado');
        },
        child: const Icon(Icons.add),
      ),
    );
  }
}
