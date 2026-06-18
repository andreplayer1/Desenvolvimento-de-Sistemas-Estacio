import 'package:flutter/material.dart';

// ---------------------- Tela de Adicionar ----------------------
class AddTaskPage extends StatefulWidget {
  const AddTaskPage({super.key});

  @override
  State<AddTaskPage> createState() => _AddTaskPageState();
}

class _AddTaskPageState extends State<AddTaskPage> {
  final TextEditingController _controller = TextEditingController();

  // Função para salvar tarefa
  void _saveTask() {
    if (_controller.text.isNotEmpty) {
      Navigator.pop(context, _controller.text); // Retorna tarefa para Home
    } else {
      // Feedback ao usuário (heurística de Nielsen: visibilidade do status)
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Digite uma tarefa antes de salvar!')),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Adicionar Tarefa')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: _controller,
              decoration: const InputDecoration(labelText: 'Nova tarefa'),
            ),
            const SizedBox(height: 20),
            ElevatedButton(onPressed: _saveTask, child: const Text('Salvar')),
          ],
        ),
      ),
    );
  }
}
