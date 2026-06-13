import 'package:flutter/material.dart';

class TaskDetailPage extends StatefulWidget {
  final String task;
  final VoidCallback onDelete;
  final Function(String) onEdit;

  const TaskDetailPage({
    super.key,
    required this.task,
    required this.onDelete,
    required this.onEdit,
  });

  @override
  State<TaskDetailPage> createState() => _TaskDetailPageState();
}

class _TaskDetailPageState extends State<TaskDetailPage> {
  late TextEditingController _controller;

  @override
  void initState() {
    super.initState();
    _controller = TextEditingController(text: widget.task);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Detalhes da Tarefa')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: _controller,
              decoration: const InputDecoration(labelText: 'Editar tarefa'),
            ),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: () {
                if (_controller.text.isNotEmpty) {
                  widget.onEdit(_controller.text);
                  Navigator.pop(context);
                } else {
                  ScaffoldMessenger.of(context).showSnackBar(
                    const SnackBar(content: Text('Digite algo válido!')),
                  );
                }
              },
              child: const Text('Salvar Alterações'),
            ),
            const SizedBox(height: 10),
            ElevatedButton(
              onPressed: () {
                widget.onDelete();
                Navigator.pop(context);
              },
              style: ElevatedButton.styleFrom(backgroundColor: Colors.red),
              child: const Text('Excluir'),
            ),
          ],
        ),
      ),
    );
  }
}
