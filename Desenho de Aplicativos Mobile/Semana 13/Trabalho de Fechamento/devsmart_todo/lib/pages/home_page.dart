import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'add_task.dart';
import 'task_detail.dart';

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  List<String> tasks = [];

  @override
  void initState() {
    super.initState();
    _loadTasks();
  }

  Future<void> _loadTasks() async {
    final prefs = await SharedPreferences.getInstance();
    setState(() {
      tasks = prefs.getStringList('tasks') ?? [];
    });
  }

  Future<void> _saveTasks() async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setStringList('tasks', tasks);
  }

  void _addTask(String task) {
    setState(() {
      tasks.add(task);
    });
    _saveTasks();
  }

  void _deleteTask(int index) {
    setState(() {
      tasks.removeAt(index);
    });
    _saveTasks();
  }

  void _editTask(int index, String newTask) {
    setState(() {
      tasks[index] = newTask;
    });
    _saveTasks();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Quest Log')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: ListView.builder(
          itemCount: tasks.length,
          itemBuilder: (context, index) {
            // 1. ACESSIBILIDADE: O leitor de tela vai ler esta frase ao focar no item
            return Semantics(
              label:
                  'Missão: ${tasks[index]}. Toque duas vezes para ver os detalhes.',
              child: Card(
                color: Theme.of(context).colorScheme.surface,
                margin: const EdgeInsets.only(bottom: 12),
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(10),
                  side: const BorderSide(
                    color: Color(0xFF2D2D2D),
                    width: 1,
                  ), // Borda discreta
                ),
                child: ListTile(
                  contentPadding: const EdgeInsets.symmetric(
                    horizontal: 16,
                    vertical: 8,
                  ),
                  title: Text(
                    tasks[index],
                    style: const TextStyle(
                      fontWeight: FontWeight.w500,
                      fontSize: 16,
                    ),
                  ),
                  // Uma setinha ciano neon para indicar que pode ser clicado
                  trailing: const Icon(
                    Icons.arrow_forward_ios,
                    size: 16,
                    color: Color(0xFF00E5FF),
                  ),
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (_) => TaskDetailPage(
                          task: tasks[index],
                          onDelete: () => _deleteTask(index),
                          onEdit: (newTask) => _editTask(index, newTask),
                        ),
                      ),
                    );
                  },
                ),
              ),
            );
          },
        ),
      ),

      // 2. ACESSIBILIDADE: O leitor de tela vai explicar o que o botão de "+" faz
      floatingActionButton: Semantics(
        label: 'Adicionar nova missão',
        child: FloatingActionButton(
          onPressed: () async {
            final newTask = await Navigator.push(
              context,
              MaterialPageRoute(builder: (_) => const AddTaskPage()),
            );
            if (newTask != null) _addTask(newTask);
          },
          child: const Icon(Icons.add),
        ),
      ),
    );
  }
}
