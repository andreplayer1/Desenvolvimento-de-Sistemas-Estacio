import 'package:flutter/material.dart';

// ---------------------- Tela de Detalhes ----------------------
class TaskDetailPage extends StatefulWidget {
  final String task; // Tarefa recebida
  final VoidCallback onDelete; // Função para excluir
  final Function(String) onEdit; // Função para editar

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
    // Inicializa campo com texto da tarefa
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Detalhes da Tarefa')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            // Campo de texto para editar tarefa
            TextField(
              controller: _controller,
              decoration: const InputDecoration(labelText: 'Editar tarefa'),
            ),
            const SizedBox(height: 20),

            // Botão para salvar edição
            ElevatedButton(
              onPressed: () {
                if (_controller.text.isNotEmpty) {
                  widget.onEdit(_controller.text); // Atualiza tarefa
                  Navigator.pop(context); // Volta para Home
                } else {
                  ScaffoldMessenger.of(context).showSnackBar(
                    const SnackBar(content: Text('Digite algo válido!')),
                  );
                }
              },
              child: const Text('Salvar Alterações'),
            ),
            const SizedBox(height: 10),

            // Botão para excluir tarefa
            ElevatedButton(
              onPressed: () {
                widget.onDelete(); // Exclui tarefa
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
